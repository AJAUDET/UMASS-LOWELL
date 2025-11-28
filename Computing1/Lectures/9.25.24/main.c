#include <stdio.h>

void f(int x);

int main(int argc, char* argv[])
{
    int x = 42;
    double y = 6.78;

    f(x);
    printf("in main x is %d\n", x);
    printf("x in main has the address of %p\n", &x); // address

    printf("Please enter an intiger: ");
    scanf("%d", &x); // looking for an integer to modify the address of x
    printf("in main x is %d\n", x);

    // while loop
    x = 0;
    while(x < 10) // loops forever because it is always true
    {
        printf("Happy Birthday %d\t", x+1);
        // other code needs x unchanged
        x++;
    }

    printf("\n\nPlease enter an intiger number greater or equal to 10: ");
    scanf("%d", &x); // looking for an integer to modify the address of x
    printf("in main x is %d\n", x);
    while(x < 10)
    {
        printf("\n\nInvalid number:\nPlease enter an intiger number greater than 10: ");
        scanf("%d", &x); // looking for an integer to modify the address of x
        printf("in main x is %d\n", x);
    }

    printf("Please enter any number greater than -2.7 and less than 4.2\n");
    scanf("%lf", &y);
    printf("in main y is %f\n", y);

    while(y < -2.7 || y > 4.2) // && is a symbol for and, || is the symbol for or
    {
        printf("\n\nInvalid Number:\nPlease enter any number greater than -2.7 and less than 4.2\n");
        scanf("%lf", &y);
        printf("in main y is %f\n", y);
    }

    x = 9;
    do
    {
        printf("Yay, x is 10\n");
    } while(x == 10);

    printf("\n\nPlease enter any number: ");
    scanf("%lf", &y); // formating a double
    printf("in main y is %f\n", y);

    return 0;
}

void f(int x)
{
    x = 100;
    printf("in f x is %d\n", x);
    printf("x in f has the address of %p\n", &x); // address

    return;
}