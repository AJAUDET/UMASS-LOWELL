#include <stdio.h>

// when writing functions always look for return type, and if it needs formal perameters
int userWishesToContinue(void);
void clearKeyboardBuffer(void);

int main(int argc, char *argv[])
{

    int x = 0;

    // both incement x
    x++; // post increment operator
    printf("x is now %d\n", x);

    ++x; // pre increment operator
    printf("x is now %d\n", x);

    printf("x++ evaluates as x then increments it %d\n", x++);
    printf("x is now %d\n", x);

    printf("++x increments x then it evavaluates as %d\n", ++x);
    printf("x is now %d\n", x);

    // PLEASE do not do stuff like below
    x = 1;
    printf("x++ + x++ + ++x + x++ evaluates as %d\n", x++ + x++ + ++x + x++);

    // this is important
    x = 2;
    if(x++ == 2)
        printf("x is now %d", x);

    x = 2;
    if(++x == 3)
        printf("x is now %d", x);

    do
    {
        x++;
        printf("%d Happy Monday\n", x);
    } while (userWishesToContinue());

    return 0;
}

int userWishesToContinue(void)
{
    char c;
    printf("Do you wish to continue (y/n): ");
    scanf("%c", &c);
    clearKeyboardBuffer();

    // while(!(c =='y' || c == 'Y' || c == 'n' || c == 'N'))
    while(c!='y' && c != 'Y' && c != 'n' && c != 'N')
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
    while(c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}