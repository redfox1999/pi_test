#include <iostream>
#include <csignal>
#include <wiringPi.h>

#include "simplog.h"

bool g_exit = false;

int selector[4] = {};   // to high selected 
int pins[8] = {};    // abcdefgh
int numbers[11] = {};  // 0,1,2,3  // low to light

void mysign_handler(int signal) {
	LOG_WARN("you press ctrl+c to quiting...");
	g_exit = true;
}



int main(int argc, const char* argv[]) {
	simplog.setLogFile("test2.log");
	signal(SIGINT, mysign_handler);
	
	LOG_INFO("Hello world!");
	
	int n = 0x3f; //0111111b;
	std::cout << n << std::endl;
	
	LOG_INFO("END!");
	return 0;
}