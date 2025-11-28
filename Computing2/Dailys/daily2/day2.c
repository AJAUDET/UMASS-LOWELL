/*
    Author: AJ Audet
    Date: 1/24/25
    Effort: 10 mins
    Purpose: Demonstrating how bitwise operator left shift (<<) interacts with 32 bit numbers

    What mathematical operation is a left shift by 1 equivalent to?
        Doubling ie: 2x

    Why does it make no sense to left shift by a number greater than 32 for 32 bit numbers?
        Shifting more than 32 bits repeats the pattern
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned int x = 1;

    for(int i = 0; i < 32; i++)
    {
        printf("%d : %u\n", i, x);
        x = (x << 1);
    }

    return 0;
}