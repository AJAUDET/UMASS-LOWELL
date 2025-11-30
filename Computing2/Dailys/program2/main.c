/*
    Program: main.c

    Author: AJ Audet

    Date: March 5 2025

    Time spent: 4 hrs 45 mins, 
    total time spent across main.c, queue.c, queue.h 9 hours

    Purpose: The purpose of this program is to recieve input data from a test file and then output results,
             and to then test the data using the UVA Online Judge for problem 11034
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* for strcmp */
#include "queue.h"

/* conversion factor of cm to m */
#define CONVERSION .01

void clearKeyboardBuffer(void);
void run_tests(int tests);
int get_length_and_side(QUEUE left, QUEUE right);
int travel(QUEUE left, QUEUE right, int length);
void load_ferry(QUEUE hQ, int length);

int main(void)
{
    int num_test;

    /* scan for number of tests to use fgets / scanf */
    scanf("%d", &num_test);
    clearKeyboardBuffer();

    run_tests(num_test);

    return 0;
}

void run_tests(int tests)
{
    QUEUE left;
    QUEUE right;
    /* test if there are any tests to run */
    if (tests <= 0)
    {
        printf("No cases entered\n");
        exit(1);
    }

    /* if there is set up variables for the length */
    int length;
    int trips_taken;

    /* test that there is at least 1 case */
    while (tests > 0)
    {
        /* create a queue for the right and left side */
        left = queue_init_def();
        right = queue_init_def();

        if (left == NULL || right == NULL)
        {
            printf("FATAL ERROR -- EXITING\n");
            /* free up the allocated memory for the initialized one*/
            if (left != NULL)
            {
                queue_destory(&left);
            }
            if (right != NULL)
            {
                queue_destory(&right);
            }
            exit(1);
        }

        /*
            now the fun stuff
            get the length of the ferry
        */
        length = get_length_and_side(left, right);

        /* cross the river */
        trips_taken = travel(left, right, length);
        
        printf("%d\n", trips_taken);

        /* free the queue for the next test */
        queue_destory(&left);
        queue_destory(&right);

        /* incriment the trips taken and decriment the tests */
        tests--;
    }
}

int get_length_and_side(QUEUE left, QUEUE right)
{
    /* create variables to track length, number of cars, car length, and which side of the river the ferry is on*/
    Status status;
    int ferry_len;
    int car_len;
    int num_cars;
    char direction[10];

    /* scan for number of cars and ferry length*/
    scanf("%d %d", &ferry_len, &num_cars);

    for (int i = 0; i < num_cars; i++)
    {
        clearKeyboardBuffer();
        /* scan for car length and direction */
        scanf("%d %s", &car_len, direction);

        /* test the string using strcmp */
        if (strcmp(direction, "left") == 0)
        {
            status = queue_enqueue(left, car_len);
        }
        else if (strcmp(direction, "right") == 0)
        {
            status = queue_enqueue(right, car_len);
        }
        else
        {
            status = FAILURE;
        }

        /* test if adding to the queue failed */
        if (status == FAILURE)
        {
            printf("Error adding car to list\n");
            if (left != NULL)
            {
                queue_destory(&left);
            }
            if (right != NULL)
            {
                queue_destory(&right);
            }

            exit(1);
        }
    }

    return ferry_len;
}

int travel(QUEUE left, QUEUE right, int length)
{
    int crossed = 0;
    /* 
        previous version i was testing 3 things at a time
        i actually feel so embarassed i can do it once by using a temp to not be an idiot
    */
    QUEUE current_bank = left;
    QUEUE other_bank = right;
    while (queue_get_size(current_bank) > 0 || queue_get_size(other_bank) > 0)
    {
        if (queue_get_size(current_bank) != 0)
        {
            load_ferry(current_bank, length);
        }
        crossed++;

        /* swap teh current bank and the other bank */
        QUEUE temp = current_bank;
        current_bank = other_bank;
        other_bank = temp;
    }

    return crossed;
}

void load_ferry(QUEUE hQ, int length)
{
    float ferry = 0.0;
    /* we have to load the ferry up */

    while (ferry < length)
    {
        /* list is empty? just quit :) */
        if (queue_get_size(hQ) == 0)
        {
            break;
        }

        /* ferry is full? quit :) */
        if (((*(queue_front(hQ, NULL)) * CONVERSION) + ferry) > length)
        {
            break;
        }

        ferry += *(queue_front(hQ, NULL)) * CONVERSION;

        queue_service(hQ);
    }
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
