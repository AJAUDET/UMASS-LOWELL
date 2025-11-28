/*
    Program: Daily 7 Assignment: day7.c
    Author: AJ Audet
    Date: 2.25.25
    Time spent: 5 hours
    Purpose: The purpose of this program is to use the UVA Online Judge to check our code before submission for UVA problem 673
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void clearKeyboardBuffer(void);

int main(int argc, char *argv[])
{
    char string[256];
    int i;
    int tests;

    // scan for how many we need to test
    scanf("%d", &tests);
    clearKeyboardBuffer();

    for (i = 0; i < tests; i++)
    {
        // fgets to read into the string we are testing using standard input
        fgets(string, sizeof string, stdin);

        if (compare(string))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

void clearKeyboardBuffer(void)
{
    char c = 'a';
    while (c != '\n')
    {
        scanf("%c", &c);
    }
}
