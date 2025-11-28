#include <stdio.h>

void joe(void) // void rwturn type means you dont need to return anything
{
    printf("Hello from Joe\n");
    // joe(); // recursive function call : function that calls itself

    return;
}

int main(int argc, char*argv[])
{
    //int x; // variable declaration
    //x = 5*2; // assignment, read x gets 5
    int x = 11; // initialize in declaration
    printf("x was assigned %d\n", x);

    x = x * 2; // x is assigned the value of x * 2 (22)
    printf("x is now %d\n", x);

    double distance;
    double rate = 11.2;
    double time = 10.5;
    distance = rate * time;
    printf("Distance traveled at rate %.2f in %.2f time is %.2f\n", rate,time,distance);

    printf("Hello from Main\n");
    joe();
    joe();

    return 0;
}