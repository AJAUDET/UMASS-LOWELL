#include <stdio.h>

void display_leading(int n, int num_left)
{
    if (num_left == 0) {return;}
    int next = n /2;
    int rem = n % 2;
    display_leading(next, num_left - 1);
    printf("%d", rem);
}

void display_trailing(float f, int num_left)
{
    if (num_left == 0) {return;}
    f *= 2.0;
    int n = f;
    f -= n;
    printf("%d", n);
    display_trailing(f, num_left - 1);
}

void display_fixed(float f, int num_leading, int num_trailing)
{
    display_leading(f, num_leading);
    printf(".");
    display_trailing(f - (int)f, num_trailing);
}

int main(void)
{
    printf("what is the number?\t" );
    float f;
    scanf("%f", &f);

    display_fixed(f, 16, 16);

    return 0;
}