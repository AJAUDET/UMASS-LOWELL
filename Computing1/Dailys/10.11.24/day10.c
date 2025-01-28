/*
    Author: AJ Audet
    Date: Oct 3, 2024
    Purpose: The Program takes an input of a negative number, but if there is no negative number reprompt user for a valid value
    Time Spent: 7 mins
*/

#include <stdio.h>

void clearKeyboardBuffer(void);

int main(int argc, char* argv[])
{   
    // declare a variable to store user input
    int number = 0;

    // Prompt user for input of a negative number
    printf("Please enter a NEGATIVE Integer: ");
    scanf("%d", &number);

    // Check if the number is negative and reprompt user if invalid input is there, use a loop
    while(number >= 0)
    {
        printf("Error- Please enter a number LESS THAN 0: ");
        scanf("%d", &number); 
        clearKeyboardBuffer();
    }

    // output the negative value the user input
    printf("The negative intiger is %d\n", number);

    return 0;
}

// clearKeyboardBuffer(): used to clear the terminal of any non intiger numbers
void clearKeyboardBuffer(void)
{
    char c = 'a';
    while(c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}