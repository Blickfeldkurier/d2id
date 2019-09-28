#include "config.h"

Config::Config(std::string file, bool debug){
	this->isDebug = debug;
	this->log = new Log(debug);
}

std::string Config::removeWhitespace(std::string line){
	auto wsfront=std::find_if_not(line.begin(),line.end(),[](int c){return std::isspace(c);});
	auto wsback=std::find_if_not(line.rbegin(),line.rend(),[](int c){return std::isspace(c);}).base();
	return (wsback<=wsfront ? std::string() : std::string(wsfront,wsback));
}

std::string Config::getHost(){
	return this->host;
}
int Config::getPort(){
	return this->port;
}

int Config::getSleepT(){
	return this->sleept;
}