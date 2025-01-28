/*
    Name: AJ Audet

    Due Date: 9/27/24

    Purpose: Converting a decimal number to binary using division and modulo
*/

#include <stdio.h>

void deciToBin(int number);

int main(int argc, char* argv[])
{
    // in main we want to create a local variable and prompt user input
    int number = 0;

    // ask user for input and collect it using scanf
    printf("Enter a positive intiger: ");
    scanf("%d", &number);

    // output the result, include the original decimal number and its binary component
    printf("%d in binary is: ", number);
    deciToBin(number);
    printf("\n");

    return 0;
}

void deciToBin(int number)
{
    // Convert decimal number to binary number
    // check if number is 0, if not move on
    if(number == 0)
    {
        printf("0");
    }
    else
    {
        // call the function again dividing by 2 to move to the next digit, then print out the remainder
        deciToBin(number/2);
        printf("%d", number % 2);
    }

    return;
}