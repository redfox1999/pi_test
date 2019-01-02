#include <iostream>
#include "simplog.h"


int main(int argc, const char* argv[]) {
	simplog.setLogFile("test2.log");
	LOG_INFO("Hello world!");
	return 0;
}