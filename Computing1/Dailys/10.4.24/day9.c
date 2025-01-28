/*
    Author: AJ Audet
    Due: Oct. 4, 2024

    Purpose: prompt for user input of a positive number, then count down then up to the inputted value

    Answer: It is different from the day6 homework because the counter is matching the inputted number rather than the number being caught in an 
            infinite loop of calling itself over and over again while decrimenting itself
*/
#include <stdio.h>

int main(int argc, char* argv[])
{
    // declare a variable to store an integer
    int number = 0;

    // prompt for user input
    printf("Enter a positive value: ");
    scanf("%d", &number);

    // loop to count down
    for(int i = number; i >= 0; i--)
    {
        printf("%d\n", i);
    }

    printf("*****\n");

    // loop to count up
    for(int i = 0; i <= number; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}