#include <stdio.h>

int main(void)
{
    int x = -21; 
    printf("x/4 = %d\n", x / 4);
    printf("x>>2 = %d\n", x>>2);
    printf("(x+(1<<2) -1)>>2 = %d\n", (x + ((1<<2) -1)) >> 2);

    return 0;
}
