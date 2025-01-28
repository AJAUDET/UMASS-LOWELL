/*
    Author: AJ Audet
    Date: 10.13.24
    Purpose: Playing Rock Paper Scissors
    Time Spent: 15 mins
*/

#include <stdio.h>

void clearKeyboardBuffer(void);
int userWishesToContinue(void);
char getInput(void);
void printResults(char playerOne, char playerTwo);

int main(int argc, char *argv[])
{
    // Declare Variables for player1 and player2 input
    char player_one_choice, player_two_choice;

    printf("Let's Play: Rock Paper Scissors\n");
    do
    {
        // prompt for & take in player1's choice accepting r, R, Rock, rock etc. rejecting any other inputs
        printf("Now it's your turn Player 1\n");
        player_one_choice = getInput();

        // output prompt for player 2 and options for (r)ock, (p)aper, (s)cissors
        printf("Player 2 Choose an option, (r)ock, (p)aper, (s)cissors\n");

        // take in player2's choice accepting r, R, Rock, rock etc. rejecting any other inputs
        printf("Now it's your turn Player 2\n");
        player_two_choice = getInput();

        // display results
        printResults(player_one_choice, player_two_choice);
        // prompt for continue
    } while (userWishesToContinue());
    return 0;
}

void printResults(char playerOne, char playerTwo)
{
    if (playerOne == playerTwo)
    {
        printf("DRAW\n");
    }
    else if ((playerOne == 'r' || playerOne == 'R') && (playerTwo == 'p' || playerTwo == 'P'))
    {
        printf("PAPER beats ROCK\n");
    }
    else if ((playerTwo == 'r' || playerTwo == 'R') && (playerOne == 'p' || playerOne == 'P'))
    {
        printf("PAPER beats ROCK\n");
    }
    else if ((playerOne == 's' || playerOne == 'S') && (playerTwo == 'R' || playerTwo == 'R'))
    {
        printf("ROCK beats SCISSORS\n");
    }
    else if ((playerTwo == 's' || playerTwo == 'S') && (playerOne == 'r' || playerOne == 'R'))
    {
        printf("ROCK beats SCISSORS\n");
    }
    else if ((playerOne == 's' || playerOne == 'S') && (playerTwo == 'p' || playerTwo == 'P'))
    {
        printf("SCISSORS beats PAPER\n");
    }
    else if ((playerTwo == 's' || playerTwo == 'S') && (playerOne == 'p' || playerOne == 'P'))
    {
        printf("SCISSORS beats PAPER\n");
    }
}

char getInput(void)
{
    char choice;

    printf("Choose an option, (r)ock, (p)aper, (s)cissors: ");
    scanf("%c", &choice);
    clearKeyboardBuffer();

    while ((choice != 'r' && choice != 'R') && (choice != 'p' && choice != 'P') && (choice != 's' && choice != 'S'))
    {
        printf("INVALID-- Please enter 'r' 'p' or 's': ");
        scanf("%c", &choice);
        clearKeyboardBuffer();
    }
    return choice;
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

void clearKeyboardBuffer(void)
{
    char c = 'a';
    while (c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}