/*
    Author: AJ Audet

    Due: 9/25/24

    Instructions: count down from 10 using recursion then after 0 print 4 asterisks

    Answer to question: <Insert the answer to
    the following question: What happens if
    the integer that you use as an argument
    is too big? Say 500000?> : You recieve a stack overflow
*/

#include <stdio.h>

void countDown(int number);

int main(int argc, char* argv[])
{
    int count = 10;
    countDown(count);
    printf("****\n");
    countDown(count);

    return 0;
}

void countDown(int number)
{
    if(number >= 0)
    {
        printf("%d\n", number);
        countDown(number -1);
    }

    return;
}