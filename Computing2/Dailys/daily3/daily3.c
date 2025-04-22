/*
    Author: AJ Audet
    Date: 1.28.24
    Effort: 15 mins
    Purpose: using bitwise operators to set a flag in a number and checking if the flag was placed successfully
*/

#include <stdio.h>

void set_flag(int *pFlag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char *argv[])
{
    int flag_holder = 0;
    int i;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    for (i = 31; i >= 0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

void set_flag(int *pFlag_holder, int flag_position)
{
    // n is shifted by the flag position in order to determine where it will "land"
    int n = 1 << flag_position;
    // *pFlag_holder will have a flag placed at the position n is at 
    *pFlag_holder = *pFlag_holder | n;
}

int check_flag(int flag_holder, int flag_position)
{
    // n is shifted by the flag position in order to determine where it will "land"
    int n = 1 << flag_position;
    // tbe bit is assigned a number wether or not the "water" can flow, if it is a 1 or a 0
    int bit = flag_holder & n;
    
    if(bit == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}