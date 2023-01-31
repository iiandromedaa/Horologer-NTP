#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <ctime>

typedef std::string string;

class utils {
	public:
		string toDTstr(time_t timeUnix);
};