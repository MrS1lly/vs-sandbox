// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <atomic>
#include <sstream>

static std::atomic<bool> stopThread = true;
static HANDLE hThread = INVALID_HANDLE_VALUE;

DWORD WINAPI ThreadProc(__in LPVOID pParam)
{
    // Simple example thread proc
    auto count = DWORD();
    while (!stopThread)
    {
        std::wstringstream ss;
        ss << L"In ThreadProc! #" << ++count << std::endl;
        OutputDebugString(ss.str().c_str());
        Sleep(1000);
    }
    
    return 0;
}

extern "C" void StopThread()
{
    if (hThread == NULL)
    {
        MessageBox(NULL, L"Error", L"Error", MB_OK);
    }
    else
    {
        stopThread = true;
        std::wstringstream ss;
        ss << L"Waiting for thread: " << (DWORD)hThread << std::endl;
        OutputDebugString(ss.str().c_str());
        WaitForSingleObject(hThread, INFINITE);
        CloseHandle(hThread);
        OutputDebugString(L"Closed Thread\n");
    }
}

extern "C" void StartThread()
{
    DWORD DllThreadID;
    
    stopThread = false;
    hThread = CreateThread(NULL, 0, ThreadProc, 0, 0, &DllThreadID);
    std::wstringstream ss;
    ss << L"Created Thread: " << (DWORD)hThread << std::endl;
    OutputDebugString(ss.str().c_str());

        
    if (hThread == NULL)
    {
        MessageBox(NULL, L"Error", L"Error", MB_OK);
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
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

