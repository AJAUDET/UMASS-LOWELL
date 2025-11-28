#include <stdio.h>

enum operation{ADD, SUB, MUL, DIV};
typedef enum operation OPERATION;

int work(int x, int y, OPERATION op)
{
    switch (op)
    {
        case ADD: return x + y;
        case SUB: return x - y;
        case MUL: return x * y;
        case DIV: return x / y;
    }
}

int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}
int mul(int x, int y)
{
    return x * y;
}
int div(int x, int y)
{
    return x / y;
}

int work2(int x, int y, int (*ftn_ptr)(int, int))
{
    return ftn_ptr(x, y);
}

int main(int argc, char* argv[])
{
    int a = 12;
    int b = 4;
    int c = 0;
    int(*ftn_ptr)(int, int) = mul;

    c = work2(a, b, ftn_ptr);
    printf("%d\n", c);

    return 0;
}