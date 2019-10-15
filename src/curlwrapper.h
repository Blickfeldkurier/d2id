#ifndef D2ID_CURLWRAPPER_H
#define D2ID_CURLWRAPPER_H

#include "log.h"
#include "config.h"
#include <curl/curl.h>

class CurlWrapper {
private:
	CURL *curl;
	Log *log;
	std::string host;
	std::string dbname;
	std::string port;
	std::string result = "";
	bool good = true;
	bool isDebug;
	void checkDB();
public:
	bool sendPost(std::string data);
	std::string getResult();
	CurlWrapper(Config *const conf, const bool debug = false);
	bool isGood();
	~CurlWrapper();
};

#endif
