#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include "process_utils.h"

void list_processes()
{
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        printf("Error: Unable to create snapshot.\n");
        return;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

    printf("+--------+----------------------------+\n");
    printf("|  PID   | Process Name               |\n");
    printf("+--------+----------------------------+\n");

    if (Process32First(hProcessSnap, &pe32))
    {
        do
        {
            printf("| %-6d | %-26s |\n", pe32.th32ProcessID, pe32.szExeFile);
        } while (Process32Next(hProcessSnap, &pe32));
    }

    printf("+--------+----------------------------+\n");

    CloseHandle(hProcessSnap);
}
