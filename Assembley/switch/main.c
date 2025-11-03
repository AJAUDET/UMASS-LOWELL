#include <stdio.h>

int main(void)
{
    int input;
    scanf("%d", &input);

    int final;
    switch (input)
    {
    case 0:
        final = 200;
        break;
    case 3:
        final += 1;
        break;
    case 9:
        final = 400;
        break;
    case 10:
        final += 2;
    case 11:
        final += input;
    default:
        final = 100;
        break;
    }
}