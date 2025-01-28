/*
    Author: AJ Audet
    Date: 10.14.24
    Purpose: Creation of a rock paper scissors game using ENUM
    Time Spent: 10 mins
*/

#include <stdio.h>

enum choice
{
    ROCK,
    PAPER,
    SCISSORS
};
typedef enum choice CHOICE;

int userWishesToContinue(void);
void clearKeyboardBuffer(void);
CHOICE getPlayerChoice(void);
void printResults(CHOICE playerOne, CHOICE playerTwo);

int main(int argc, char *argv[])
{
    CHOICE playerOne, playerTwo;

    do
    {
        // prompt for player one input and display options of rock paper or scissors
        printf("Player 1 it's your turn\n");
        playerOne = getPlayerChoice();

        // prompt for player two input and display options of rock paper or scissors
        printf("Player 2 it's your turn\n");
        playerTwo = getPlayerChoice();

        // print results
        printResults(playerOne, playerTwo);

    } while (userWishesToContinue());

    return 0;
}

void printResults(CHOICE playerOne, CHOICE playerTwo)
{
    if (playerOne == playerTwo)
    {
        printf("DRAW\n");
    }
    else if ((playerOne == ROCK && playerTwo == PAPER) || (playerOne == PAPER && playerTwo == ROCK))
    {
        printf("PAPER beats ROCK\n");
    }
    else if ((playerOne == SCISSORS && playerTwo == PAPER) || (playerOne == PAPER && playerTwo == SCISSORS))
    {
        printf("SCISSORS beats PAPER\n");
    }
    else if ((playerOne == ROCK && playerTwo == SCISSORS) || (playerOne == SCISSORS && playerTwo == ROCK))
    {
        printf("ROCK beats SCISSORS\n");
    }
}

CHOICE getPlayerChoice(void)
{
    char userInput;
    printf("Please enter (r)ock, (p)aper, or (s)cissors: ");
    scanf("%c", &userInput);
    clearKeyboardBuffer();

    while ((userInput != 'r' && userInput != 'R') && (userInput != 'p' && userInput != 'P') && (userInput != 's' && userInput != 'S'))
    {
        printf("IMVALID -- Please enter 'r' 'p' or 's': ");
        scanf("%c", &userInput);
        clearKeyboardBuffer();
    }

    switch (userInput)
    {
    case 'r':
    case 'R':
        return ROCK;
    case 'p':
    case 'P':
        return PAPER;
    case 's':
    case 'S':
        return SCISSORS;
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

int userWishesToContinue(void)
{
    char c;
    printf("Do you wish to continue (y/n): ");
    scanf("%c", &c);
    clearKeyboardBuffer();

    while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
    {
        printf("Invalid Input-- Do you wish to continue (y/n): ");
        scanf("%c", &c);
        clearKeyboardBuffer();
    }

    return (c == 'y' || c == 'Y');
}