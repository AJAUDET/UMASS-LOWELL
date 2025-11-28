#include <stdio.h>

int main(int argc, char* argv[])
{
    int x;
    x = 5;

    printf("x evaluates as %d\n", x);
    printf("&x evaluates as %p\n", &x);

    // create a pointer 
    int* p; // the * modifier creates the variable as a pointer

    p = &x;

    printf("*p evaluates as %d\n", *p); // RETRIEVE the value of the variable
    printf("p evaluates as %p\n", p);
    printf("&p evaluates as %p\n", &p);

    *p = 7; // modifies the address

    printf("x evaluates as %d\n", x); // now value of x is 7
    printf("&x evaluates as %p\n", &x); // address is the same

    // modifying a variable using only pointers 
    int y;
    p = &y;

    printf("p evaluates as %p\n", p);
    printf("&y evaluates as %p\n", &y);
    printf("&p evaluates as %p\n", &p);

    *p = 99;
    printf("*p evaluates as %d\n", *p);
    printf("y evaluates as %d\n", y);


    return 0;
}