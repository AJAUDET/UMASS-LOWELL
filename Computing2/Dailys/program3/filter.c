/*
    Program: filter.c
    Author: AJ Audet
    Date: April 15 2025
    Time spent: 6hrs total, 4 in filter.c, 1 main.c, and 1 in debugging
    Purpose: The purpose of this program is to act as the implementation file for the custom functions declared in filter.h 
    Notes: honestly this was really fun, I mainly just combined the generic vector code and sorting into one file and changed up names
           of functions, I got really lost when it came to the actual filtering of the numbers, that tripped me up for a while
           Honestly most of this stuff came to me in delusions of what I thought shoudl work, and a lack of sleep, so its probably really
           janky tbh
*/

#include "filter.h"
#include <stdio.h>
#include <stdlib.h>

struct my_filter
{
    int capacity;
    int size;
    int *data;
};
typedef struct my_filter My_filter;

void swap(int *a, int *b);

MY_FILTER init_filter_default(void)
{
    My_filter *pFilter = (My_filter *)malloc(sizeof(My_filter));
    if (pFilter != NULL)
    {
        // pick arbitrary values for size & capacity
        pFilter->capacity = 1;
        pFilter->size = 0;

        // malloc for data, it can fail, test for quasimoto state
        pFilter->data = (int *)malloc(sizeof(int) * pFilter->capacity);
        if (pFilter->data == NULL)
        {
            free(pFilter);
            pFilter = NULL;
        }
    }
    return pFilter;
}

Status insert_to_filter(MY_FILTER hFilter, int item)
{
    My_filter *pFilter = (My_filter *)hFilter;
    int *temp;
    int i;
    if (pFilter->size >= pFilter->capacity)
    {
        temp = (int *)malloc(sizeof(int) * pFilter->capacity);
        if (temp == NULL)
        {
            return FAILURE;
        }
        for (i = 0; i < pFilter->size; i++)
        {
            temp[i] = pFilter->data[i];
        }
        free(pFilter->data);
        pFilter->data = temp;
        pFilter->capacity *= 2;
    }
    pFilter->data[pFilter->size] = item;
    pFilter->size++;
    return SUCCESS;
}

int get_size(MY_FILTER hFilter)
{
    My_filter *pFilter = (My_filter *)hFilter;
    return pFilter->size;
}

int get_capacity(MY_FILTER hFilter)
{
    My_filter *pFilter = (My_filter *)hFilter;
    return pFilter->capacity;
}

int *item_at(MY_FILTER hFilter, int index)
{
    My_filter *pFilter = (My_filter *)hFilter;
    if (index < 0 || index >= pFilter->size)
    {
        return NULL;
    }
    return &pFilter->data[index];
}

void sort_items_in_filter(MY_FILTER hFilter)
{
    My_filter *pFilter = (My_filter *)hFilter;
    int i;
    int j;
    int swapped_something;

    for (i = 0; i < pFilter->size; i++)
    {
        swapped_something = 0;
        for (j = 0; j < pFilter->size - 1 - i; j++)
        {
            if (pFilter->data[j] > pFilter->data[j + 1])
            {
                swap(pFilter->data + j, pFilter->data + j + 1);
                swapped_something = 1;
            }
        }
        if (!swapped_something)
        {
            break;
        }
    }
}

Status filter_items(MY_FILTER hFilter)
{
    My_filter *pFilter = (My_filter *)hFilter;
    int *temp;
    int *filtered_items;
    int is_same;
    int index = 0;
    int size = pFilter->size;

    int i;
    int j;

    temp = (int *)malloc(sizeof(int) * pFilter->capacity);
    if (temp == NULL)
    {
        return FAILURE;
    }

    temp[index] = pFilter->data[0];
    index++;

    for (i = 1; i < size; i++)
    {
        is_same = 0;
        for (j = 0; j < index; j++)
        {
            if (pFilter->data[i] == temp[j])
            {
                is_same = 1;
                pFilter->size--;
                pFilter->capacity--;
                break;
            }
        }

        if (is_same == 1)
        {
            continue;
        }
        temp[index] = pFilter->data[i];
        index++;
    }
    free(pFilter->data);
    filtered_items = (int *)malloc(sizeof(int) * pFilter->capacity);
    if (filtered_items == NULL)
    {
        return FAILURE;
    }
    for (i = 0; i < pFilter->size; i++)
    {
        filtered_items[i] = temp[i];
    }
    pFilter->data = filtered_items;
    return SUCCESS;
}

void destroy_filter(MY_FILTER *phFilter)
{
    My_filter *pFilter = (My_filter *)*phFilter;
    free(pFilter->data);
    free(pFilter);
    *phFilter = NULL;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
