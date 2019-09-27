#include "config.h"

Config::Config(std::string file){

}

std::string Config::removeWhitespace(std::string line){
	auto wsfront=std::find_if_not(line.begin(),line.end(),[](int c){return std::isspace(c);});
	auto wsback=std::find_if_not(line.rbegin(),line.rend(),[](int c){return std::isspace(c);}).base();
	return (wsback<=wsfront ? std::string() : std::string(wsfront,wsback));
}
