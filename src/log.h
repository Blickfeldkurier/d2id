#ifndef DTOID_LOG_H
#define DTOID_LOG_H

#include <string>
#include <iostream>

class Log {
public:
	Log(bool debug);
	void print(std::string text);
	void print(std::string debug_txt, std::string log_txt);
private:
	bool debug;

};

#endif
