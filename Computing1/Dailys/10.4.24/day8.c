/*
    Author: AJ Audet
    Due: Oct. 4, 2024

    Purpose: The purpose of this program is to figure out if a number is even or odd. if even: devide by 2 / if odd: tripple then add 1 
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    // declare a variable to store an integer
    int number = 0;

    // prompt for user input
    printf("Enter a real number: ");
    scanf("%d", &number);

    // check if number is even or odd, then output the correct statement
    if(number % 2 == 0)
    {
        printf("The next value of the number is: %d\n", number/2);
    }
    else
    {
        printf("he next value of the number is: %d\n", number*3 + 1);
    }

    return 0;
}