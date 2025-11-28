#include <stdio.h>

void clearKeyboardBuffer(void);

int main(void)
{
    int x = 11;

    if(x == 11)
    {
        printf("I like\n");
        printf("What a wonderful day\n");
    }

    if(x == 11)
    {
        printf("I like\n");
        printf("What a wonderful day\n");
    }

    x = 0;
    while(x < 10) // remember this pattern
    {
        printf("Happy birthday\t");
        x++;
        printf("%d\n", x);
    }
    printf("\n********\n");
    while(x+5 < 25) // do NOT remember this pattern
    {
        printf("Happy birthday\t");
        x++;
    }

    printf("\n********\n");

    /*
    // most likely not what you wanted
    scanf("Please enter X: %d", &x); // if there is text in the scanf function you need to EXACTLY INPUT it as it is written
    printf("You entered %d for X\n", x);

    // most likely what you wanted
    printf("Please enter X: ");
    scanf("%d\n", &x); // if there is text in the scanf function you need to EXACTLY INPUT it as it is written
    printf("You entered %d for X", x);
    */

    x = 0;
    printf("Please enter a number between 10 & 20: ");
    scanf("%d\n", &x); 

    while(x < 10 || x > 20)
    {
        printf("Invalid:\nPlease enter a number between 10 & 20: ");
        scanf("%d\n", &x); 
        clearKeyboardBuffer();
    }
    printf("You entered %d", x);

    return 0;
}

void clearKeyboardBuffer(void)
{
    char c = 'a';
    while(c != '\n')
    {
        scanf("%c", &c);
    }
}