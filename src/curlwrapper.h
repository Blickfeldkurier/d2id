#ifndef D2ID_CURLWRAPPER_H
#define D2ID_CURLWRAPPER_H

#include "log.h"
#include "config.h"

class CurlWrapper {
private:
	Log *log;
	bool isDebug;
public:
	CurlWrapper(const Config &conf, const bool debug = false);
};

#endif
