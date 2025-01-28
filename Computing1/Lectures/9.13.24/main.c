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


    return 0;
}