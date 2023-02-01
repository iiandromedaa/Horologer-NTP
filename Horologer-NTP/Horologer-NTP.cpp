#include <iostream>
#include <chrono>
#include <Windows.h>
#include <tchar.h>
#include <iomanip>
#include <cstdlib>
#include <thread>

#include "UtilityFuncs.h"

//DEFINES

const int BUFFER_SIZE = 32;
char server_ip[BUFFER_SIZE]{"192.168.1.1"};

typedef std::string string;

#define ALARM_MENU_SET 1
#define SETTING_MENU_NTP 2
#define SETTING_MENU_DISP 3
#define HELP_MENU_ABOUT 4

#ifndef UNICODE
#define UNICODE
#endif 

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void clockloop();
void pingtest(string); //RETURNS void PARAMS string address
void AddMenus(HWND);

HMENU hMenu;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"MainWindow";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Horologer NTP",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 600, 600,

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
    case WM_COMMAND:
        switch (wParam) {
            case 1:
                MessageBeep(MB_OK);
                break;
            case 2:
                break;
            case 3:
                break;
        }
        break;
    case WM_CREATE:
        AddMenus(hwnd);
        break;
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

void AddMenus(HWND hWnd) {
    hMenu = CreateMenu();
    HMENU hAlarmsMenu = CreateMenu();
    HMENU hSettingsMenu = CreateMenu();
    HMENU hHelpMenu = CreateMenu();
;
    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hAlarmsMenu, L"Alarms");
    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hSettingsMenu, L"Settings");
    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, L"Help");

    AppendMenuW(hAlarmsMenu, MF_STRING, ALARM_MENU_SET, L"Set Alarms");
    AppendMenuW(hSettingsMenu, MF_STRING, SETTING_MENU_NTP, L"NTP Settings");
    AppendMenuW(hSettingsMenu, MF_STRING, SETTING_MENU_DISP, L"Display Settings");
    AppendMenuW(hHelpMenu, MF_STRING, HELP_MENU_ABOUT, L"About");

    SetMenu(hWnd, hMenu);
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
