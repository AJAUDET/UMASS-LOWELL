/*
    Author: AJ Audet
    Date: 1.30.25
    Effort: 10 mins
    Purpose: repurposing daily 3 to include a way to unset a flag ie using the bitwise not operator
*/
#include <stdio.h>

void set_flag(unsigned int *flag_holder, int flag_position);
void unset_flag(unsigned int *flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char *argv[])
{
    unsigned int flag_holder = 0;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);

    display_32_flags(flag_holder);

    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);

    display_32_flags(flag_holder);
    return 0;
}

void set_flag(unsigned int *flag_holder, int flag_position)
{
    // n is shifted by the flag position in order to determine where it will "land"
    int n = 1 << flag_position;
    // *flag_holder will have a flag placed at the position n is at
    *flag_holder = *flag_holder | n;
}
void unset_flag(unsigned int *flag_holder, int flag_position)
{
    // n is shifted by the flag position in order to determine where it will "check"
    int n = 1 << flag_position;
    // *flag_holder will have a flag removed at the position n is at by using the bitwise ~(not) operator
    *flag_holder = *flag_holder & ~(*flag_holder & n);
}

int check_flag(unsigned int flag_holder, int flag_position)
{
    // n is shifted by the flag position in order to determine where it will "land"
    int n = 1 << flag_position;
    // tbe bit is assigned a number wether or not the "water" can flow, if it is a 1 or a 0
    int bit = flag_holder & n;

    return (bit == 0) ? 0 : 1;
}

void display_32_flags(unsigned int flag_holder)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}