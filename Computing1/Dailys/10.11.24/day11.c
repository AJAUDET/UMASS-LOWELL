/*
    Author: AJ Audet
    Date: Oct 3, 2024
    Purpose: Take user input in range of 1-79 and output the desired number of asterisks, if values are outside of range reprompt user
    Time Spent: 7 mins

*/

#include <stdio.h>

void clearKeyboardBuffer(void);

int main(int argc, char* argv[])
{
    // Declare variable to store user input
    int numAsterisk = 0;

    // Prompt for user input
    printf("How many Asterisks would you like to print out? ");
    scanf("%d", &numAsterisk);

    // Reprompt if input is out of range (1-79)
    while(numAsterisk < 1 || numAsterisk > 79)
    {
        printf("Error- Please enter a value in range of 1-79: ");
        scanf("%d", &numAsterisk);
        
        // use function clearKeyboardBuffer to remove unwanted values/characters
        clearKeyboardBuffer();
    }

    // output asterisks
    printf("Printing %d Asterisks\n", numAsterisk);
    for(int i = 0; i < numAsterisk; i++)
    {
        printf("*");
    }

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