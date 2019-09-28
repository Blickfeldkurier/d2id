#ifndef D2ID_CURLWRAPPER_H
#define D2ID_CURLWRAPPER_H

#include "log.h"
#include "config.h"

class CurlWrapper {
private:
	Log *log;
	std::string host;
	int port;
	bool isDebug;
public:
	CurlWrapper(Config *const conf, const bool debug = false);
};

#endif
