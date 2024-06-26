// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <cstdio>
#include <iostream>
#include <string>

std::string GetLastErrorAsString()
{
    //Get the error message ID, if any.
    DWORD errorMessageID = ::GetLastError();
    if (errorMessageID == 0) {
        return std::string(); //No error message has been recorded
    }

    LPSTR messageBuffer = nullptr;

    //Ask Win32 to give us the string version of that message ID.
    //The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    //Copy the error message into a std::string.
    std::string message(messageBuffer, size);

    //Free the Win32's string's buffer.
    LocalFree(messageBuffer);

    return message;
}

extern "C" __declspec(dllexport) bool _RegisterHotKey(HWND hwd, int id_register, int vk)
{

    if (AllocConsole())
    {
        FILE* fDummy;
        freopen_s(&fDummy, "CONOUT$", "w", stdout);
        std::cout.clear();
        setlocale(LC_ALL, "Russian");


    }
    bool status = RegisterHotKey(hwd, id_register, MOD_ALT | MOD_NOREPEAT, vk);
    std::string error = std::system_category().message(::GetLastError());
    std::cout << "Status reg: " << status << std::endl;



    std::cout << error << std::endl;
    return status;
}
extern "C" __declspec(dllexport) bool _UnregisterHotKey(HWND hwd, int id_register)
{
    return UnregisterHotKey(NULL, id_register);
}
MSG msg;
extern "C" __declspec(dllexport) int _GetMessage()
{
    GetMessage(&msg, NULL, 0, 0);
    return msg.message;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

