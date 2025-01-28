#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("65\n"); // evaluates as the first character in the string
    printf("%d\n", 65); // 65 evaluates as 65, evaluates as the first char in the string, %d for outputting integers
    printf("%d, %d\n", 30+35,20+45);

    printf("%c\n", 65); // %c for characters
    printf("%c\n", 'A');// single quotes for single characters
    printf("%d\n", 'A'); // prints out 65

    printf("%c\n", 'A'+1); // 'A'+1 == 65+1 == 'B'
    printf("%d\n", 'A'+1);

    printf("%d\n", '0'); // what do we expect, 48
    printf("%d\n", 0); // what do we expect, 0

    printf("%e\n", 6.02e23); // scientific notation
    printf("%g\n", 6.02e23); // general notation
    printf("%d\n", 6.02e23); // unexpected - interpret floating point as int
    printf("%.5f\n", 3.14159); // the .5 removes the extra 0 added

    printf("%f\n", .1);
    printf("%g\n", .1);
    printf("%d\n", .1); // unexpected - interpret floating point as int

    printf("%.1f\n", .1);

    printf("%.14f\n", .1);

    printf("%.20f\n", .1); // starts adding 5's after the 16th decimal position causing rounding errors

    printf("%c\n", 'A');
    printf("%d\n", 'A');

    printf("%d\n", 'A'+2);
    printf("%c\n", 'A'+2);

    printf("%c\n", 55); // character '7'
    printf("%d\n", 55);
    printf("%d\n", 55.0); // something unexpected
    printf("%e\n", 55); // why?
    printf("%e\n", 55.0); 
    printf("%g\n", 55); // why?
    printf("%g\n", 55.0);

    return 0;
}