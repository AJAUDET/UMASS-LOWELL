/*
    Author: AJ Audet

    Purpose: I wanted to make blackjack, and this is good practice for enums/structs
*/
#include <stdio.h>
#include <stdlib.h> // for srand
#include <time.h>   // to use system time fro randomness

// use structs and enums to store rank and type for the cards

enum suit
{
    HEARTS,
    SPADES,
    CLUBS,
    DIAMONDS
};
typedef enum suit SUIT;

enum rank
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};
typedef enum rank RANK;

struct card
{
    SUIT suit;
    RANK rank;
};
typedef struct card CARD;

void clearKeyboardBuffer(void);
int userWishesToContinue(void);
void printCards(CARD card1, CARD card2);
void printValues(CARD card1, CARD card2);

int main(int argc, char *argv[])
{
    // use randomness(time) to distribute cards of the player and computer
    srand(time(NULL));

    CARD userCard1, userCard2, compCard1, compCard2;

    // assign a random card to the user
    userCard1.rank = (rand() % 13) + 1;
    userCard1.suit = rand() % 4;

    userCard2.rank = (rand() % 13) + 1;
    userCard2.suit = rand() % 4;

    printf("Player Cards: \n");
    printCards(userCard1, userCard2);

    // do the same for computer's cards
    compCard1.rank = (rand() % 13) + 1;
    compCard1.suit = rand() % 4;

    compCard2.rank = (rand() % 13) + 1;
    compCard2.suit = rand() % 4;

    printf("\n*****************\n\n");

    printf("Computer's Cards: \n");
    printCards(compCard1, compCard2);

    printf("\n*****************\n\n");

    printValues(userCard1, userCard2);

    return 0;
}

// 10.8.24: Change display if rank is ACE,JACK, QUEEN, KING
void printCards(CARD card1, CARD card2)
{
    switch (card1.rank)
    {
    case ACE:
        printf("----------------\n");
        printf("| A            |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            A |\n");
        printf("----------------\n");
        break;
    case JACK:
        printf("----------------\n");
        printf("| J            |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            J |\n");
        printf("----------------\n");
        break;
    case QUEEN:
        printf("----------------\n");
        printf("| Q            |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            Q |\n");
        printf("----------------\n");
        break;
    case KING:
        printf("----------------\n");
        printf("| K            |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            K |\n");
        printf("----------------\n");
        break;
    default:
        // print card 1
        printf("----------------\n");
        printf("| %d            |\n", card1.rank);
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            %d |\n", card1.rank);
        printf("----------------\n");
        break;
    }

    switch (card2.rank)
    {
    case ACE:
        printf("----------------\n");
        printf("| A            |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            A |\n");
        printf("----------------\n");
        break;
    case JACK:
        printf("----------------\n");
        printf("| J            |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            J |\n");
        printf("----------------\n");
        break;
    case QUEEN:
        printf("----------------\n");
        printf("| Q            |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            Q |\n");
        printf("----------------\n");
        break;
    case KING:
        printf("----------------\n");
        printf("| K            |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            K |\n");
        printf("----------------\n");
        break;
    default:
        // print card 2
        printf("----------------\n");
        printf("| %d            |\n", card2.rank);
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|              |\n");
        printf("|            %d |\n", card2.rank);
        printf("----------------\n");
        break;
    }
    return;
}

// 10.8.24: Known issue when looping the switch when checking for invalid values, fix this at a later date
void printValues(CARD card1, CARD card2)
{
    // declare variables to store the values of the rank of the cards
    int val1, val2, total;
    char answer = 'a';

    val1 = card1.rank;
    val2 = card2.rank;

    if (val1 > 10)
    {
        val1 = 10;
    }
    if (val2 > 10)
    {
        val2 = 10;
    }

    if (val1 == 1 || val2 == 1)
    {
        printf("Do you want to use your ACE as a 1 or 11? Y for 1, N for 11: ");
        scanf("%c", &answer);
        clearKeyboardBuffer();

        switch (answer)
        {
        case 'y':
        case 'Y':
            if (val1 == 1)
            {
                total = val2 + 1;
            }
            else if (val2 == 1)
            {
                total = val1 + 1;
            }
            printf("Your total is %d\n", total);
            clearKeyboardBuffer();
            break;
        case 'n':
        case 'N':
            if (val1 == 1)
            {
                total = val2 + 11;
            }
            else if (val2 == 1)
            {
                total = val1 + 11;
            }
            printf("Your total is %d\n", total);
            clearKeyboardBuffer();
            break;

        default:
            printf("INVALID-- Please try again: ");
            clearKeyboardBuffer();
        }
    }
    else
    {
        total = val1 + val2;
        printf("Your total is %d\n", total);
    }

    return;
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