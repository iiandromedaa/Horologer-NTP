#include <iostream>
#include <chrono>
#include <Windows.h>
#include <tchar.h>
#include <thread>

#include "UtilityFuncs.h"

typedef std::string string;

//int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) {
//	to-do: actually use winmain
//}

void clockloop();
void pingtest(string);

int main() {
	std::thread thr(pingtest, "www.google.com");
	for (int i = 0; i < 20; i++) {
		clockloop();
		Sleep(750);
	}
}



void clockloop() {
	time_t current = time(NULL);
	char ctimeBuffer[30];
	std::cout << utils::toDTstr(current, sizeof(ctimeBuffer), ctimeBuffer) << std::endl;
}

void pingtest(string address) {
	for (int i = 0; i < 20; i++) {
		string command = "ping " + address;
		int p = system(command.c_str());
		if (p == 0) {
			std::cout << "win !!";
		}
		else {
			std::cout << "fail :(";
		}
	}
}