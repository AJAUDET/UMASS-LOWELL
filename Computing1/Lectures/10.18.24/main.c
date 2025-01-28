#include <stdio.h>

int myPowRecursive(int base, int exp);
int myPowLooped(int base, int exp);

void outputEvenSquaresFrom2toMax(int max);


int main(int argc, char *argv[])
{
    printf("myPowRecursive(5,3) is %d\n", myPowRecursive(5,3));
    printf("myPowRecursive(5,0) is %d\n", myPowRecursive(5,0));

    printf("myPowLooped(5,3) is %d\n", myPowLooped(5,3));
    printf("myPowLooped(5,0) is %d\n", myPowLooped(5,0));

    outputEvenSquaresFrom2toMax(10);

    // expression evaluation
    int a = 2, b = 5, c = 3;
    printf("%d < %d evaluates as %d\n", a, b, a < b);
    printf("%d < %d evaluates as %d\n", b, c, b < c);

    printf("%d < %d < %d evaluates as %d\n", a, b, c, a < b < c);
        // this breaks down further, a < b = 1, then is 1 < 3 yes
    
    printf("%d < %d && %d < %d evaluates as %d\n", a, b, b, c, a < b && b < c);
    return 0;
}

void outputEvenSquaresFrom2toMax(int max)
{
    int i = 0;
    for(i = 2; i <= max; i+=2)
    {
        printf("%d * %d is %d\n", i, i, i*i);
    }
}

int myPowRecursive(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    return base * myPowRecursive(base, exp - 1);
}

int myPowLooped(int base, int exp)
{
    int result = 1;
    if(exp == 0 )
    {
        return 1;
    }
    else
    {
        for(int i = exp; i > 0; i--)
        {
            result *= base;
        }
        return result;
    }
}