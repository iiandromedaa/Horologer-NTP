#include <iostream>
#include <chrono>
#include <Windows.h>
#include <tchar.h>

#include "UtilityFuncs.h"

typedef std::string string;

//int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) {
//	std::cout << "hi";
//}

void clockloop();
std::atomic_bool halt = false;

int main() {
	clockloop();
}



void clockloop() {
	auto start = std::chrono::system_clock::now();
	auto start_t = std::chrono::system_clock::to_time_t(start);
	time_t start2 = time(0);
	//std::cout << utils::toDTstr(start_t) << std::endl;
	char ctimeBuffer[50];
	std::cout << ctime_s(ctimeBuffer, sizeof(ctimeBuffer), &start2) << std::endl;
}