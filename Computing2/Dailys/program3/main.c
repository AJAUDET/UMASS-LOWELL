/*
    Program: main.c
    Author: AJ Audet
    Date: April 15 2025
    Time spent: 7 hrs
    Purpose: The purpose of this program is to take a list of numbers from 0 <-> 2000000000 and filter out duplicates
             then sorting that list, stopping the process of getting numbers when -1 is read/input
*/

#include <stdio.h>
#include <stdlib.h>
#include "filter.h"

void clearKeyboardBuffer(void);

int main(void)
{
    MY_FILTER hFilter = NULL;
    int i;
    int temp = 0;
    int size;

    hFilter = init_filter_default();
    if (hFilter == NULL)
    {
        printf("Failed to create filter\n");
        exit(1);
    }

    scanf("%d", &temp);
    clearKeyboardBuffer();
    while(temp != -1)
    {
        scanf("%d", &temp);
        clearKeyboardBuffer();
        if (temp != -1 && temp >= 0 && temp <= 2000000000)
        {
            insert_to_filter(hFilter, temp);
        }
    }

    filter_items(hFilter);
    size = get_size(hFilter);
    sort_items_in_filter(hFilter);

    for (i = 0; i < size; i++)
    {
        printf("%d\n", *item_at(hFilter, i));
    }

    destroy_filter(&hFilter);
    return 0;
}

void clearKeyboardBuffer(void)
{
    char c = 'a';
    while (c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}