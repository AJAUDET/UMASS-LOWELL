#include <stdio.h>


// enum : similar to an array, first item is lowest value, initially starys at 0
    // we are creating a set of enumerated values
enum suit {HEARTS = 2, DIAMONDS, SPADES = 5, CLUBS};
typedef enum suit Suit;

enum rank {TWO = 2, THREE, FOUR, /*other ranks*/ TEN = 10, JACK, QUEEN, KING, ACE};
typedef enum rank Rank;

// struct : holds more than one variable
struct card
{
    Suit suit;
    Rank rank;
};
typedef struct card Card;

typedef int joesNumber;

// global variables are placed outside of main
    // const : unchangeable variable
const int twoOfHearts = 1;
const int HEARTS_ORG = 1;
const int TWO_ORG = 2;

evaluate_cards(Card c1, Card c2);

int main(int argc, char* argv[])
{
    struct card card1;

    Card card2;

    joesNumber n;
    int n1;

    int card = 1; // two of hearts

    if (card == twoOfHearts)
    {
        printf("I got the Two of Hearts\n");
    }

    card1.suit = HEARTS;
    card1.rank = TWO;

    if(card1.suit == HEARTS && card1.rank == TWO)
    {
        printf("I got the Two of Hearts\n");
    }

    return 0;
}

Card evaluate_cards(Card c1, Card c2)
{
    Card c;
    if(c1.rank > c2.rank)
    {
        return;
    }
}