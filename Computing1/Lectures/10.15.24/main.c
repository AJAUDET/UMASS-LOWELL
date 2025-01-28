#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mySqrt(double x);
double mySqrtV2(double x);

int main(int argc, char *argv[])
{
    printf("mySqrt(7) is %g\n", mySqrt(7));
    printf("sqrt(7) is %g\n", sqrt(7));
    printf("pow(5, 3) is %g\n", pow(5, 3)); // C converts these ints to doubles -implicit casting
    printf("pow(7, .5) is %g\n", pow( (double) 7, .5)); // type casting is explicit casting

    int a = 3;
    int b = 4;
    
    double c;
    c = a/b;
    printf("%d / %d is %g\n", a, b, c);

    c = (double) a / (double) b; // explicit casting (type casting)
    printf("%d / %d is %g\n", a, b, c);

    printf("abs(-7) is %d\n", abs(-7));
    // labs = long int - abs are in stdlib.h

    printf("fabs(-5.23) is %g\n", fabs(-5.23)); // fabs is in math.h

    printf("ceil(5.23) is %g\n", ceil(5.23)); // next highest number

    printf("floor(5.23) is %g\n", floor(5.23)); // next lowest number

    return 0;
}

double mySqrt(double x)
{
    double guess = x / 2.0;
    double low = 0;
    double high = x;

    // for (int i = 0; i < 25; i++)
    int i = 0;
    while(fabs(guess * guess - x) > 0.0001)
    {
        guess = (low + high) / 2.0;
        printf("%d guess if %g: guess*guess is %g, error %g\n", i+1, guess, guess*guess, guess*guess-x);
        if(guess*guess > x)
        {
            high = guess;
        }
        else
        {
            low = guess;
        }

        i++;
    }

    return guess;
}

double mySqrtV2(double x)
{
    double guess = x / 2.0;
    // double low = 0;
    // double high = x;

    // for (int i = 0; i < 25; i++)
    int i = 0;
    while(fabs(guess * guess - x) > 0.0001)
    {
        printf("%d guess if %g: guess*guess is %g, error %g\n", i+1, guess, guess*guess, guess*guess-x);
        if(guess*guess > x)
        {
            guess = 0.999 * guess;
        }
        else
        {
            guess = 1.001 * guess;
        }

        i++;
    }

    return guess;
}