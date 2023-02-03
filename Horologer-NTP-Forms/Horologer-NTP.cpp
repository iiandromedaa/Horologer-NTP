#include <iostream>
#include <chrono>
#include <Windows.h>
#include <tchar.h>
#include <iomanip>
#include <cstdlib>
#include <thread>

#include "UtilityFuncs.h"
#include "configparser.hpp"

//DEFINES

typedef std::string string;

string path = "config.ini";
// Initialize the parser with a path to the configuration file
ConfigParser parser = ConfigParser(path);

#define ALARM_MENU_SET 1
#define SETTING_MENU_NTP 2
#define SETTING_MENU_DISP 3
#define HELP_MENU_ABOUT 4

#ifndef UNICODE
#define UNICODE
#endif 

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProcAbout(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void AddMenus(HWND);
void CreateAboutWindow(HINSTANCE);
bool AboutWindowOpen = false;

HMENU hMenu;
HINSTANCE Minstance;

//MAIN PROCESS

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"MainWindow";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);
    Minstance = hInstance;

    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Horologer NTP",    // Window text
        WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 600, 600,

        HWND_DESKTOP,       // Parent window    
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

//CREATE ABOUT WINDOW

void CreateAboutWindow(HINSTANCE hInstance, HWND ParentWindow) {
    
    const wchar_t ABOUT_CLASS[] = L"AboutWindow";

    WNDCLASS wcabout = { };

    wcabout.lpfnWndProc = WindowProcAbout;
    wcabout.hInstance = hInstance;
    wcabout.lpszClassName = ABOUT_CLASS;

    RegisterClass(&wcabout);

    wcabout.hbrBackground = (HBRUSH)(COLOR_BACKGROUND+1);

    HWND hwndabout = CreateWindowEx(
        0,                              // Optional window styles.
        ABOUT_CLASS,                     // Window class
        L"About",    // Window text
        WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 150,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );
    SetMenu(hwndabout, NULL);
    ShowWindow(hwndabout, SW_SHOW);
    if (hwndabout == NULL)
    {
        return;
    }
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

//WINDOW PROC

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
            case 4:
                if (!AboutWindowOpen) {
                    AboutWindowOpen = true;
                    CreateAboutWindow(GetModuleHandle(NULL), hwnd);
                }
                break;
        }
        break;
    case WM_CREATE:
        AddMenus(hwnd);
        break;
    case WM_DESTROY:
        ExitProcess(0);
        return 0;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        //FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

//WINDOW PROC ABOUT

LRESULT CALLBACK WindowProcAbout(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        break;
    case WM_DESTROY:
        AboutWindowOpen = false;
        return 0;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.
        //std::vector<LPCWSTR> aboutText;
        TCHAR aboutText[] = L"Hello World!";
            TextOut(hdc, 50, 37.5, aboutText, _tcslen(aboutText));

        //FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

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