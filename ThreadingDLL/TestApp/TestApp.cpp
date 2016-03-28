#include <Windows.h>

// A function pointer called MYPROC which points to a function (in this case, a procedure) 
// that takes no arguments (the void on the right) and returns nothing (the void on the left) 
// This ensures type-safety when calling GetProcAddress
typedef void(__cdecl *MYPROC)(void);

int main(void)
{
    // Load the library
    auto hLib = LoadLibrary(L"ThreadedDll.dll");
    
    // Get function pointers to our start and stop thread procs
    auto startProc = (MYPROC)GetProcAddress(hLib, "StartThread");
    auto stopProc = (MYPROC)GetProcAddress(hLib, "StopThread");

    // Ensure that the pointers are valid
    if (!startProc || !stopProc)
    {
        FreeLibrary(hLib);
        return 1;
    }

    // Start the thread, and then stop after 5s
    startProc();
    Sleep(5000);
    stopProc();

    // Unload the lib
    FreeLibrary(hLib);

    return 0;
}