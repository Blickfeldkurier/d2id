#ifndef DTOID_CONFIG_H
#define DTOID_CONFIG_H

#include <string>
#include <iostream>
#include <algorithm>

class Config {
private:
	std::string removeWhitespace(std::string line);
public:
	Config(std::string  file);
};

#endif
