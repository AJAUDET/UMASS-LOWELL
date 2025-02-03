/* 

MINI NOTES

<< bitwise operator Left-Shift

    _<<_ : thing on the left is shifted by the number on the right
            values become truncated(never seen again)
            if the shift is more than the bits you have the number becomes undefined

    >> bitwise operator Right-Shift
        works the same way for POSITIVE NUMBERS ONLY

    & bitwise and
    | bitwise or
*/
#include <stdio.h>
#include <stdlib.h>
#include "date.h"


int main(int argc, char* argv[])
{
    DATE hToday;

    hToday = date_init_default();
    if(hToday == NULL)
    {
        printf("Failed to allocate space for date object\n");
        exit(1);
    }


    date_output(hToday); 


    date_destroy(&hToday); 
    return 0;
}

