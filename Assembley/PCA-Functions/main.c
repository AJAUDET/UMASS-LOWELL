#include <stdio.h>

int reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, reg8, reg9, reg10, reg11, reg12, reg13, reg14, reg15;
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

// reg0 <- return value
// reg1 <- 1st argument
void my_abs(void)
{
    reg0 = reg1;            // int rv = a;
    comp(reg1, 0);
    if (GTE) goto ELSE;     //if (a < 0)
    reg0 = reg0 * -1;       // rv = -1 * rv;

ELSE:
                            // return rv;
}


int main(int argc, char* argv[])
{
    reg5 = -7;          // int w = -7;
    reg1 = reg5;        // 'w' as an argument
    my_abs();          // int x = abs(w);

    printf("%d\n", reg0);

    return 0;
}

