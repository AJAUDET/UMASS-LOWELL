#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void my_math(int a, int b, int *pTimes, double *pAverage);
void getDouble(double *pD);
void fillArrayWithRandomNumbers(int arr[], int size);
void getInt(int *pI);
void outputSumOfAdjacentPairs(int arr[], int size);

int main(int argc, char *argv[])
{
    int a = 5;
    int b = 4;
    int c;
    double d;
    int array[10];

    srand(time(NULL));

    my_math(a, b, &c, &d);
    printf("%d * %d is %d, avg is %.2f\n", a, b, c, d);
    getDouble(&d);
    printf("d is now %g\n", d);

    fillArrayWithRandomNumbers(array, sizeof(array) / sizeof(array[0]));
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
        printf("array[%d] is %d\n", i, array[i]);

    // overwrite the fourth element with user input using getInt
    // getInt(&array[3]);
    getInt(array + 3); // equivalent to ln 30
    // getInt(&*(array + 3)); // extremely silly, & cancels out * 
    
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
        printf("array[%d] is %d\n", i, array[i]);

    outputSumOfAdjacentPairs(array, sizeof(array) / sizeof(array[0]));

    return 0;
}

void my_math(int a, int b, int *pTimes, double *pAverage)
{
    *pTimes = a * b;
    *pAverage = (a + b) / 2.0;
}

void getDouble(double *pD)
{
    printf("Please enter a number: ");
    scanf("%lf", pD);
}

void getInt(int *pI)
{
    printf("Please enter a number: ");
    scanf("%d", pI);
}

void fillArrayWithRandomNumbers(int arr[], int size)
{

    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = rand() % 101;
    }
}

void outputSumOfAdjacentPairs(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        printf("%d\n", arr[i] + arr[i+1]);
    }
}