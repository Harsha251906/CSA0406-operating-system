#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>

DWORD getParentPID(DWORD pid) {
    DWORD ppid = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(hSnapshot, &pe)) {
            do {
                if (pe.th32ProcessID == pid) {
                    ppid = pe.th32ParentProcessID;
                    break;
                }
            } while (Process32Next(hSnapshot, &pe));
        }
        CloseHandle(hSnapshot);
    }
    return ppid;
}

int main() {
    DWORD pid = GetCurrentProcessId();
    DWORD ppid = getParentPID(pid);

    printf("Current Process ID  : %lu\n", pid);
    printf("Parent Process ID   : %lu\n", ppid);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create child process (same program)
    if (CreateProcess(
        NULL,
        "child.exe",   // change if exe name is different
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi)) {

        printf("\nChild Process Created Successfully!\n");
        printf("Child PID : %lu\n", pi.dwProcessId);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        printf("\nChild Process Creation Failed!\n");
    }

    return 0;
}

