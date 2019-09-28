#include "curlwrapper.h"

CurlWrapper::CurlWrapper(Config *const config, const bool debug){
	this->isDebug = debug;
	this->log = new Log(debug);
	this->host = config->getHost();
	this->port = config->getPort();
}
