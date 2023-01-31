#include <iostream>
#include <chrono>
#include <Windows.h>
#include <tchar.h>
#include <iomanip>
#include <cstdlib>
#include <thread>

#include "UtilityFuncs.h"
//#include "libconfig.hh"
#include "ping.h"


const int BUFFER_SIZE = 32;
char server_ip[BUFFER_SIZE]{"192.168.1.1"};

typedef std::string string;
//using namespace libconfig;

void clockloop();
void pingtest(string); //RETURNS void PARAMS string address

#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    ping(server_ip);
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main() {
	//std::thread thr(ping(server_ip));
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
