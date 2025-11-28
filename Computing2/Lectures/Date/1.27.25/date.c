#include <stdio.h>
#include <stdlib.h>
#include "date.h"

struct date // known type
{
    int month;
    int day;
    int year;
};
typedef struct date Date;

DATE date_init_default(void)
{
    Date* pDate = (Date*)malloc(sizeof(Date));
    if(pDate != NULL)
    {
        pDate->month = 1;
        pDate->day = 1;
        pDate->year = 1970;
    }

    return pDate;
}

void date_output(DATE hDate) // interface function
{
    Date* pDate = (Date*)hDate; // casting to known type, explicitly
    printf("%d/%d/%d\n", pDate->month, pDate->day, pDate->year); // -> combination of * and . notation, 
    // use a . if the left is a struct, use an -> if the left is a pointer to a struct
}

void date_destroy(DATE* phDate)
{
    Date* pDate = (Date*)*phDate; // cast to the known type, dereferencing the pointer to the handle
    free(pDate);

    *phDate = NULL; // cleaning up the dangling pointer
}