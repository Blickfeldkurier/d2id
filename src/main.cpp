#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <getopt.h>

void printHelp(){
    std::cout << "Usage:\n";
    std::cout << "\t./d2id [options]\n";
    std::cout << "Options:\n";
    std::cout << "\t-c/--config <path>: Path to config file";
    std::cout << "\t-h/--help: Print thist Help\n";
}

int main(int argc, char *argv[]){
    static struct option long_options[] = {
        {"config", required_argument, 0, 'c'},
        {"help", no_argument, 0, 'h' },
        {0, 0, 0, 0}
    };

    int opt = 0;
    int option_index = 0;
    std::string config_path = "./test.conf";
    while ((opt = getopt_long(argc, argv,"h", 
                   long_options, &option_index )) != -1) 
    {
        switch(opt){
            case 'c':{
                char *fullPath = realpath(optarg, NULL);
                config_path = std::string(fullPath);
            }break;
            case 'h':{
                printHelp();
                exit(0);
            }break;
            case '?':{
                std::cout << "Could not find argument. You you want some --help\n";
                exit(1);
            }
        }
    }

    bool running = true;
    while(running){
        
    }

    return 0;
}
