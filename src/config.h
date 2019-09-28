#ifndef DTOID_CONFIG_H
#define DTOID_CONFIG_H

#include <string>
#include <iostream>
#include <algorithm>
#include "log.h"

class Config {
private:
	bool isDebug;
	Log *log;
	std::string host;
	int port;
	int sleept;
	std::string removeWhitespace(std::string line);
public:
	Config(std::string  file, bool debug = false);
	std::string getHost();
	int getPort();
	int getSleepT();
};

#endif
