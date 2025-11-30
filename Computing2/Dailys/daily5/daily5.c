/*
    Author: AJ Audet
    Date: 2.2.25
    Effort: 20 mins
    Purpose: Contunuation of daily 3-4 to display and check flags, this time using an array
*/
#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char *argv[])
{
    // Set the first integer to zero and all others to zero by default
    unsigned int flag_holder[5] = {0}; 

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);

    display_flags(flag_holder, 5);
    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);

    display_flags(flag_holder, 5);
    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
    // the bit to set needs to be the flag position
    int set_bit = flag_position;

    // dividing by 32 allows us to find the right "area" to set the bit
    flag_position /= 32;

    // flag holder at flag position uses the |(or) operator to set the bit in that position
    flag_holder[flag_position] |= (1 << (set_bit % 32));
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
    int unset_bit = flag_position;
    flag_position /= 32;

    // flag holder at flag position uses the &(and) operator to unset the bit in that position due to the ~(or) gving us the oposite number
    flag_holder[flag_position] &= ~(1 << (unset_bit % 32));
}

int check_flag(unsigned int flag_holder[], int flag_position)
{
    int bit_check = flag_position;
    flag_position /= 32;

    // using the turnary operator to display a 1 or a 0 for printing the array
    return ((flag_holder[flag_position] >> bit_check) & 1)?1:0;
}

// code copied over from daily 4
void display_flags_as_array(unsigned int flag_holder)
{
    int i = 0;
    while(i < 32)
    {
        printf("%d", check_flag(&flag_holder, i));
        i++;
        if(i % 4 ==0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void display_flags(unsigned int flag_holder[], int size)
{
    for(int i = 0; i < size; i++)
    {
        display_flags_as_array(flag_holder[i]);
    }
}