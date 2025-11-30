#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

int main(int argc, char *argv[])
{
    BIT_FLAGS *hBit_flags;
    int num_of_bits;

    printf("Enter how many bits you have: ");
    scanf("%d", &num_of_bits);

    hBit_flags = bit_flags_init_number_of_bits(num_of_bits);

    printf("Did the flag place(1 yes: 0 no)? %d : %d : %d\n", bit_flags_set_flag(hBit_flags, 6), bit_flags_set_flag(hBit_flags, 0), bit_flags_set_flag(hBit_flags, 5));

    printf("Size: %d\n", bit_flags_get_size(hBit_flags));

    printf("Capacity: %d\n", bit_flags_get_capacity(hBit_flags));

    printf("Checking Flag: %d : %d : %d \n", bit_flags_check_flag(hBit_flags, 6), bit_flags_check_flag(hBit_flags, 0), bit_flags_check_flag(hBit_flags, 5));

    printf("Did the flag unset(1 yes: 0 no)? %d : %d : %d\n", bit_flags_unset_flag(hBit_flags, 6), bit_flags_unset_flag(hBit_flags, 0), bit_flags_unset_flag(hBit_flags, 5));

    printf("Size: %d\n", bit_flags_get_size(hBit_flags));

    printf("Capacity: %d\n", bit_flags_get_capacity(hBit_flags));

    printf("Checking Flag: %d : %d : %d \n", bit_flags_check_flag(hBit_flags, 6), bit_flags_check_flag(hBit_flags, 0), bit_flags_check_flag(hBit_flags, 5));

    bit_flags_destroy(hBit_flags);
    return 0;
}