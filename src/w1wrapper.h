#ifndef D2ID_W1WRAPPER_H
#define D2ID_W1WRAPPER_H

#include <string>
#include <list>
#include <exception>
#include "config.h"
#include "log.h"

class W1Wrapper{
public:
	typedef struct Temp{
		float value;
		bool valid;
	} Temp;
	class W1NotFoundException : public std::exception {
	public:
		char * what();
	};
	W1Wrapper(Config *const config, const bool debug = false);
	Temp getTemp(std::string device);
	Temp getTemp(int device);
	int getNumDevices();
	std::string getDeviceName(int index);
	int getDeviceNum(std::string name);
	std::list<std::string> getDevices();
private:
	bool isDebug;
	const std::string baspath = "/sys/bus/w1/devices/";
	const std::string devicelist = "w1_bus_master1/w1_master_slaves";
	const std::string tempfile = "w1_slave";
	Log *log;
	std::list<std::string> devices;
};
#endif
