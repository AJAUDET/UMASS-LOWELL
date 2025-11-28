/*
    Author: AJ Audet
    Date: Start: October 23 2024 // End: October 24 2024
    Purpose: Take a starting number and an ending number and complete the The Collatz Conjecture: if even n/2 // if odd 3n + 1
                and see how many steps it takes to reach 1
    Time Spent: Day 1: 20 Mins // Day 2: 10 Mins // Total Time Spent 30 Mins
    
*/

#include <stdio.h>

void collatzConjecture(int start, int end);
int getStart(void);
int getEnd(int start);

int main(void)
{
    int start, end;

    // assign a value to start
    start = getStart();

    // assign a value to end
    end = getEnd(start);

    collatzConjecture(start, end);

    return 0;
}

int getStart(void)
{
    int number;
    do
    {
        printf("Enter a starting number: ");
        scanf("%d", &number);
    } while (number <= 1);
    
    return number;
}

int getEnd(int start)
{
    int number;
    do
    {
        printf("Enter an ending number: ");
        scanf("%d", &number);
    } while (number <= start);

    return number;
}

// even n/2
// odd 3n + 1
void collatzConjecture(int start, int end)
{
    int steps = 0;
    int number = start;

    while(number != 1)
    {
        steps++;
        if(number % 2 == 0)
        {
            number /= 2;
        }
        else
        {
            number = number * 3 + 1;
        }
    }

    printf("%10d:%d\t\t ", start, steps);

    if(start < end)
    {
        collatzConjecture(start + 1, end);
    }
}