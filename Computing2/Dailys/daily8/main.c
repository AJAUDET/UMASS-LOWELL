/*
    Author: AJ Audet
    Program: main.c
    Date: April 10 2024
    Time Spend: 10 mins
    Purpose: main file where I tested if my implementation of priority queues was correct, 
        using time.h to create unique testing values for each run through of the program aided in accurately debugging my functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // used to seed the random numbers
#include "priority_queue.h"

int main(void)
{
    PRIORITY_QUEUE hQueue = NULL;
    hQueue = priority_queue_init_default();
    
    // if it failed to create the queue crash 
    if(hQueue == NULL)
    {
        printf("Failed to create a Queue\n");
        exit(1);
    }

    srand(time(NULL)); // actuallty getting random values every loop for testing

    int priority;
    int data;
    int i;

    for(i = 0; i < 20; i++)
    {
        priority = rand() % 101; // give a priority to the numbers from 0-100
        data = rand() % 101; // give a number 0-100
        priority_queue_insert(hQueue, priority, data);
        printf("DATA: %d :: PRIORITY: %d\n",data, priority);
    }

    while(!priority_queue_is_empty(hQueue))
    {
        printf("Front: %d\n", priority_queue_front(hQueue, NULL));
        priority_queue_service(hQueue);
    }

    priority_queue_destroy(&hQueue);

    return 0;
}