#include "config.h"

Config::Config(std::string file, bool debug){
	this->isDebug = debug;
	this->log = new Log(debug);
	std::ifstream config(file);
	if(config.good()){
		std::string line;
		while(std::getline(config, line)){
			this->parseConfig(this->removeWhitespace(line));
		}
		config.close();
	}else{
		this->log->print("Could not open: " + file + " -> Using defaults");
	}
}

std::string Config::removeWhitespace(std::string line){
	auto wsfront=std::find_if_not(line.begin(),line.end(),[](int c){return std::isspace(c);});
	auto wsback=std::find_if_not(line.rbegin(),line.rend(),[](int c){return std::isspace(c);}).base();
	return (wsback<=wsfront ? std::string() : std::string(wsfront,wsback));
}

void Config::parseConfig(std::string line){
	if(line.empty() || line[0] == '#'){
		return;
	}
	std::string global_delim = "=";
	int pos = line.find(global_delim);
	if(pos == std::string::npos){
		return;
	}
	std::string key = this->removeWhitespace(line.substr(0, pos));
	std::string token = this->removeWhitespace(line.substr(pos + 1, token.length()));
	if(key.compare("host") == 0){
		this->log->print("Influx host: " + token);
		this->host = token;
		return;
	}
	if(key.compare("port") == 0){
		this->log->print("Influx Port: " + token);
		this->port = token;
		return;
	}
	if(key.compare("sleep") == 0){
		this->log->print("Sleep: " + token);
		this->sleept = std::stoi(token);
		return;
	}
	if(key.compare("dbname") == 0){
		this->log->print("DBName: " + token);
		this->dbname = token;
	}
	std::string dev_delim = ".";
	int dev_pos = key.find(dev_delim);
	std::string dev_name = key.substr(0, dev_pos);
	std::string dev_token = key.substr(dev_pos + 1, key.length());

}

std::string Config::getHost(){
	return this->host;
}
std::string Config::getPort(){
	return this->port;
}

int Config::getSleepT(){
	return this->sleept;
}

std::string Config::getDBName(){
	return this->dbname;
}