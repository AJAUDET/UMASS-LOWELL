#include <stdio.h>

void myIntSwap(int *px, int *py);
void getRange(double *pMin, double *pMax);
void clearKeyboardBuffer(void);

int main(int argc, char *argv[])
{
    int a = 2, b = 3, c = 4;

    int *p, d, *pD; // d is an int, pD is and int*

    p = &b;

    printf("%p %d\n", p, *p);
    *p = 5;

    printf("b is now %d\n", b);

    for (int i = -5; i <= 5; i++)
        // printf("%d %p %d\n", i, p+i, *(p+i)); // each adress is now 4 bytes apart due to an integer only holding 4 bytes
        printf("%d %p %d\n", i, &p[i], p[i]); // *p = p[0]

    *(p + 1) = 77;

    printf("a is %d and &a is %p\n", a, &a);

    printf("%p %d\n", p, *p);
    printf("%p %d\n", &*p, *&*p);

    int **q; // pointer to a pointer
    q = &p;

    printf("%p %d\n", *q, **q);

    printf("a is %d, b is %d\n", a, b);
    myIntSwap(&a, &b);
    printf("a is %d, b is %d\n", a, b);

    double min = 0.0, max = 100.0;
    printf("Range is from %g to %g\n", min, max);
    getRange(&min, &max);
    printf("Range is from %g to %g\n", min, max);

    return 0;
}

void myIntSwap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

void getRange(double *pMin, double *pMax)
{
    int noc;
    printf("Enter a range: ");
    noc = scanf("%lf%lf", pMin, pMax);
    clearKeyboardBuffer();

    while(noc != 2 || (*pMin >= *pMax))
    {
        printf("Invalid -- Enter a range: ");
        noc = scanf("%lf%lf", pMin, pMax);
        clearKeyboardBuffer();
    }
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