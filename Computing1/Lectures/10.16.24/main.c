#include <stdio.h>
#include <math.h>

double mySqrtBabylonian(double);

int main(int argc, char *argv[])
{
    printf("mySqrtBabylonian(7) is %g\n", mySqrtBabylonian(7));
    return 0;
}

double mySqrtBabylonian(double num)
{
    double guess = num / 2.0;
    int counter = 0;

    while (fabs(guess * guess - num) > 0.001)
    {
        printf("%d: guess %g, guess*guess %g, error %g\n", ++counter, guess, guess * guess, guess * guess - num);
        guess = (guess + num / guess) / 2.0;
    }

    return guess;
}