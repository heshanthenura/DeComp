#include <iostream>
#include "process_utils.h"

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

        printf("1. Print Process List\n");
        printf("2. Print Process Details\n");
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