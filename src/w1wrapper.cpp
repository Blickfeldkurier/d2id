#include "w1wrapper.h"

W1Wrapper::W1Wrapper(){

}

W1Wrapper::Temp W1Wrapper::getTemp(std::string device){
	W1Wrapper::Temp tmp;
	return tmp;
}
W1Wrapper::Temp W1Wrapper::getTemp(int device){
	W1Wrapper::Temp tmp;
	return tmp;

}
int W1Wrapper::getNumDevices(){
	return 0;
}
std::string W1Wrapper::getDeviceName(int index){
	return "";
}
int W1Wrapper::getDeviceNum(std::string name){
	return 0;
}
std::list<std::string> W1Wrapper::getDevices(){
	this->devices;
}
