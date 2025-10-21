

int r0, r1, r2, r3, r4, r5, r6, r7, r8;
int LT, LTE, GT, GTE, EQ, NEQ;

void comp(int a, int b)
{
    LT = a < b;
    LTE = a <= b;
    GT = a > b;
    GTE = a >= b;
    EQ = a == b;
    NEQ = a != b;
}

#include <stdio.h>

int main(int argc, char* argv[])
{
    r0 = 5; //int num = 5;
    r1 = r0 % 2;
    comp(r1, 1);

    if(NEQ) goto ELSE;
    printf("odd\n");
    goto DONE;
ELSE:
    printf("Even\n");
DONE:
/*
    if(num%5 == 1)
        printf("odd\n");
    else
        printf("even\n");
*/
    return 0;
}