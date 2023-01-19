#include <string>
#include <iostream>
#include <thread>
#include <Windows.h>

using namespace std;

// The function we want to execute on the new thread.

void task() {
    HANDLE hprcess = NULL;
    HANDLE hthread = NULL;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD dwProcessId = 0;
    DWORD dwThreaId = 0;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&si, sizeof(pi));
    BOOL bCreateProcess = NULL;
    BOOL nCreateProcess = NULL;
    DWORD Ret = 0, dwPID = 0, dwTID = 0, dwPver = 0;

    dwPID = GetCurrentProcessId();
    cout << "Current PID" << dwPID << endl;
    dwPID = GetCurrentThreadId();
    cout << "Current TID" << dwPID << endl;
    cout << "Command Line: %s\n" << GetCommandLine() << endl;
    dwPver = GetProcessVersion(dwPID);
    dwPID = GetCurrentThreadId();
    cout << "Current PV" << dwTID << endl;
    cout << "Starting child process\n" << endl;
    bCreateProcess = CreateProcessW(
        L"C:\\Program Files\\Windows NT\\Accessories\\wordpad.exe",
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );
    if (bCreateProcess == FALSE)
    {
        cout << "Failed";
    }
    else {
        cout << "Process Creation Successful!";
        cout << "PID" << pi.dwProcessId << endl;
        cout << "TID" << pi.dwThreadId << endl;
    }
    nCreateProcess = CreateProcessW(
        L"C:\\Windows\\System32\\notepad.exe",
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );
    if (nCreateProcess == FALSE)
    {
        cout << "Failed";
    }
    else {
        cout << "Process Creation Successful!";
        cout << "PID" << pi.dwProcessId << endl;
        cout << "TID" << pi.dwThreadId << endl;
    }
}
int main()
{
    for (size_t i = 0; i < 5; i++)
    {
        thread t1(task);
        Sleep(1000);
        t1.join();
        if (i == 3)
        {
            abort();
        }
    }
}
