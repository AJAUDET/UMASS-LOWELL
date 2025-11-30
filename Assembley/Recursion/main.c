#include <stdio.h>

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n*factorial(n-1);
}

int main(void)
{
    int num = 0;
    scanf("%d", &num);
    printf("%d\n", factorial(num));

    return 0;
}