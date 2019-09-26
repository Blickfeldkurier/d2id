#include "curlwrapper.h"

CurlWrapper::CurlWrapper(const Config &config, const bool debug){
	this->isDebug = debug;
	this->log = new Log(debug);
}
