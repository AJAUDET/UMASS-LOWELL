/*
    using bitwise operators and bit assignment to display/store values
*/
#include <stdio.h>
enum toppings {
    MAYO = 1,
    PICKLES = 2,
    JALEPENOS = 4,
    BACON = 8,
    LETTUCE = 16,
    ONIONS = 32,
};
typedef enum toppings Toppings;

void display_toppings(Toppings t)
{
    if (t & MAYO)
        printf("MAYO\n");
    if (t & PICKLES)
        printf("PICKLES\n");
    if (t & JALEPENOS)
        printf("JALEPENOS\n");
    if (t & BACON)
        printf("BACON\n");
    if (t & LETTUCE)
        printf("LETTUCE\n");
    if (t & ONIONS)
        printf("ONIONS\n");
}

int main(void)
{
    Toppings jake = MAYO | PICKLES | BACON; // mayo with pickles with bacon
    Toppings son = ~jake; // not jake, everything that jake didnt have

    display_toppings(son);

    return 0;
}


