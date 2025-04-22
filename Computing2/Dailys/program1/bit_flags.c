/*
    Author: AJ Audet
    Date: 9 Feb. 2025
    Time Took: 75 mins
    Purpose: to combine opaque object design philosophy with the BitCheck dailys
    Interface Proposal: a display_bit function would be pretty useful for debugging purposes,
                        so we can physiocally see that the bit changed rather than assuming it was
*/

#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

struct bit_flags // known type
{
    int size;
    int capacity;
    unsigned int *data;
};
typedef struct bit_flags Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    Bit_flags *pBit_flags = (Bit_flags *)malloc(sizeof(Bit_flags)); // allocate memory
    if (pBit_flags != NULL)
    {
        pBit_flags->capacity = 32;         // capacity needs to be 32 bits as a baseline
        pBit_flags->size = number_of_bits; // size is the number of bits used

        while (number_of_bits >= pBit_flags->capacity)
        {
            // capacity needs to increase by 32 if the number of bits is larger than 32, 64,etc...
            pBit_flags->capacity += 32;
        }

        // allocate space for an unsigned int*
        pBit_flags->data = (unsigned int *)malloc(sizeof(unsigned int) * pBit_flags->capacity);

        // check if valid after allocation
        if (pBit_flags == NULL)
        {
            free(pBit_flags);
            pBit_flags = NULL;
        }

        // fill in the bits as 0's
        for (int i = 0; i < pBit_flags->size; i++)
        {
            pBit_flags->data[i] = 0;
        }
    }

    return pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    unsigned int *temp;
    Bit_flags *pBit_flags = (Bit_flags *)hBit_flags; // cast to the known type
    while (flag_position >= pBit_flags->capacity)
    {
        // allocate memory to temp that accounts for the position being outside of bit range
        temp = (unsigned int *)malloc(sizeof(unsigned int) * (pBit_flags->capacity));
        if (temp == NULL)
        {
            return FAILURE;
        }

        // set temp[i] to the value of pBit->data[i]
        for (int i = 0; i < pBit_flags->size; i++)
        {
            temp[i] = pBit_flags->data[i];
        }

        // free data and copy over temp while increasing capacity to account for flag position being outside of range
        free(pBit_flags->data);
        pBit_flags->capacity += 32;
        pBit_flags->data = temp;
    }

    // if the flag position is out of the range of size, new size is the flags position + 1
    if (flag_position >= pBit_flags->size)
    {
        pBit_flags->size = flag_position + 1;
    }

    // set the flag by finding the "segment" of 32 bits the flag it is supposed to be in and use the |(or) operator to set the flag
    pBit_flags->data[flag_position / 32] |= (1 << (flag_position));

    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    unsigned int *temp;
    Bit_flags *pBit_flags = (Bit_flags *)hBit_flags; // cast to the known type
    while (flag_position >= pBit_flags->capacity)
    {
        // allocate memory to temp that accounts for the position being outside of bit range
        temp = (unsigned int *)malloc(sizeof(unsigned int) * (pBit_flags->capacity));
        if (temp == NULL)
        {
            return FAILURE;
        }

        // set temp[i] to the value of pBit->data[i]
        for (int i = 0; i < pBit_flags->size; i++)
        {
            temp[i] = pBit_flags->data[i];
        }

        // free data and copy over temp while increasing capacity to account for flag position being outside of range
        free(pBit_flags->data);
        pBit_flags->data = temp;
        pBit_flags->capacity += 32;
    }

    // if the flag position is out of the range of size, new size is the flags position + 1
    if (flag_position >= pBit_flags->size)
    {
        pBit_flags->size = flag_position + 1;
    }

    // set the flag by finding the "segment" of 32 bits the flag it is supposed to be in and use the |(or) operator to set the flag
    pBit_flags->data[flag_position / 32] &= ~(1 << flag_position);

    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    Bit_flags *pBit_flags = (Bit_flags *)hBit_flags;
    int bit = 0;
    int bit_to_check = flag_position;
    if (flag_position < 0 || flag_position > pBit_flags->size)
    {
        bit = -1;
    }
    else
    {
        flag_position /= pBit_flags->capacity;
        if ((pBit_flags->data[flag_position] >> bit_to_check) & 1)
        {
            bit = ((pBit_flags->data[flag_position] >> bit_to_check) & 1);
        }
    }

    return bit;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
    Bit_flags *pBit_flags = (Bit_flags *)hBit_flags;
    return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
    Bit_flags *pBit_flags = (Bit_flags *)hBit_flags;
    return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS *phBit_flags)
{
    Bit_flags *pBit_flags = (Bit_flags *)*phBit_flags; // cast to the known type
    free(pBit_flags->data);
    free(pBit_flags);

    *phBit_flags = NULL;
}