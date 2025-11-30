#include <stdio.h>

int sum_of_8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return a + b + c + d + e + f + g + h;
}

int main(void)
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 7;
    int h = 8;

    printf("The sum is: %d", sum_of_8(a, b, c, d, e, f, g, h));

    return 0;
}