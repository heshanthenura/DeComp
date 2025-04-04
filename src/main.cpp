#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <stdbool.h>

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

int main()
{
    printf("\n");

    printf("  DDDD    EEEEE   CCCCC   OOOOO   M   M  PPPPP  \n");
    printf("  D   D   E       C       O   O   MM MM  P   P \n");
    printf("  D   D   EEEE    C       O   O   M M M  PPPPP  \n");
    printf("  D   D   E       C       O   O   M   M  P      \n");
    printf("  DDDD    EEEEE   CCCCC   OOOOO   M   M  P      \n");

    printf("\n");

    printf("DeComp - A tool allow you to do various memory operations\n\n");

    int ans;

    while (true)
    {

        printf("0. Print Process List\n");
        printf("1. Print Process Details\n");
        printf("\n");
        printf("Select Option Number (or enter 0 to exit):-");
        scanf("%d", &ans);
        printf("\n");

        if (ans == 0)
        {
            printf("Exiting program...\n");
            break;
        }
        else if (ans == 1)
        {
            list_processes();
        }
        else
        {
            printf("Please enter valid option\n");
        }

        printf("\n\n");
    }

    return 0;
}
