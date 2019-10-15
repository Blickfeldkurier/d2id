#include "curlwrapper.h"

static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp){
	if(userp == nullptr){
		return 0;
	}
	std::string *res = static_cast<std::string *>(userp);
	res->append(std::string(contents));
	size_t newLength = size*nmemb;
	return newLength;
}

CurlWrapper::CurlWrapper(Config *const config, const bool debug){
	this->isDebug = debug;
	this->log = new Log(debug);
	this->host = config->getHost();
	this->port = config->getPort();
	this->dbname = config->getDBName();
	this->curl = curl_easy_init();
	this->checkDB();
}

bool CurlWrapper::isGood(){
	return this->good;
}

void CurlWrapper::checkDB(){
	std::string querryDBs = "query?q=show databases";
	bool stat = sendPost(querryDBs);
	if(stat == false){
		return;
	}
	if(this->result.find(this->dbname) == std::string::npos){
		log->print("Influx DB not found - Create DB: " + this->dbname);
		std::string createDB = "query?q=CREATE DATABASE " + this->dbname;
		bool isCreated = sendPost(createDB);
		if(isCreated == false){
			this->good = false;
			log->print("Could not create Influx DB: " + this->dbname);
		}
	}
}

CurlWrapper::~CurlWrapper(){
	curl_easy_cleanup(this->curl);
}

bool CurlWrapper::sendPost(std::string data){

	if(this->curl != nullptr){
		return false;
	}
	this->result = "";
	CURLcode res;
	struct curl_slist* headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");

	std::string url = "http://" + this->host + ":" + this->port + "/" + data;

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->result);

    res = curl_easy_perform(curl);
	
	if(res != CURLE_OK)
        {
            this->log->print("curl_easy_perform() failed: " + std::string(curl_easy_strerror(res)));
        }

    curl_slist_free_all(headers);

	return true;
}

std::string CurlWrapper::getResult(){
	return this->result;
}