#include <stdio.h>

union combined
{
    float f;
    int i;
};
typedef union combined Combined;


int main(int argc, char* argv[])
{
    Combined t;
    t.i = 0x7F800000;
    printf("%.64f\n", t.f);

    return 0;
}