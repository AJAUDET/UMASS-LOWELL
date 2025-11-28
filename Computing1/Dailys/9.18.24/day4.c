/*
    Author: Arthur "AJ" Audet

    Date Created: 9/17/24

    Instructions: Print 42 as an intiger, the character 'J', and a flaoting point number ie. 3.14159

    Libraries Used: <stdio.h> for standarnd i/o
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    // integers use %d
    printf("An example of an integer is %d, it uses %%d to print itself\n", 42);

    // characters use %c
    printf("To print a character use %%c, an example of a character is \'%c\'\n", 'J');

    // floating point numbers use %f
    printf("To print a floating point we use %%f, an example of a floating point number is %f\n", 3.14159);

    return 0;
}

