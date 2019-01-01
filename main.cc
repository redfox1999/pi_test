#include <csignal>
#include <iostream>
#include <wiringPi.h>
#include "simplog.h"

bool g_exit = false;

void mysign_handler(int signal) {
	LOG_WARN("you press ctrl+c to quiting...");
	g_exit = true;
}


int main(int argc, const char* argv[]) {
	int major = 0;
	int minor = 0;
	int Gpio21 = 0;
	
	signal(SIGINT, mysign_handler);
	
	LOG_INFO("this is wiringPi GPIO test....");
	
	wiringPiVersion(&major, &minor);	
	
	LOG_INFO("wiringPi Version: %d.%d", major, minor);
	
	int r = wiringPiSetupGpio();
	LOG_INFO("wiringPiSetupGpio result = %d", r);
	
	Gpio21 = wpiPinToGpio(21);
	
	pinMode(Gpio21, OUTPUT);
	
	while (!g_exit) {
		LOG_INFO("write GPIO.21 to HIGH");
	
		digitalWrite(Gpio21, HIGH);
	
		delay(1000);
	
		LOG_INFO("write GPIO.21 to LOW");
		digitalWrite(Gpio21, LOW);
	
		delay(1000);
	}
	
	wiringPiSetup();
	
	LOG_INFO("END!");
	
}
