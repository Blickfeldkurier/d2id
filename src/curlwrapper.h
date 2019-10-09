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
	int port;
	bool isDebug;
public:
	std::string sendPost(std::string data);
	CurlWrapper(Config *const conf, const bool debug = false);
};

#endif
