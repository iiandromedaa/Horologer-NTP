#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <ctime>

typedef std::string string;

class utils {
	public:
		static char* toDTstr(time_t timeUnix, size_t size, char* ctimeBuffer) {
			ctime_s(ctimeBuffer, size, &timeUnix);
			return ctimeBuffer;
		}
		static void sysPing(string target) {
			string sysPingCmd = "ping " + target;
			system(sysPingCmd.c_str());
		}
};