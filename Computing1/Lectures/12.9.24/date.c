#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "date.h"

struct date
{
    int month;
    int day;
    int year;
};
typedef struct date Date; // known data type

int dateValidate(int m,int d,int y);

DATE dateInitDefault()
{
    Date* pDate;
    pDate = malloc(sizeof(Date));
    if(pDate == NULL)
    {
        printf("Error allcating memory -- Exiting");
        exit(1);
    }

    pDate->month = 1;// arrow means dereference
    (*pDate).day = 1; // equal to line 23
    pDate->year = 1970;

    return pDate;
}

dateDestroy(DATE hDate)
{
    Date* pDate = (Date*)hDate; // casting to the known data type
    free(pDate);
}

int dateSet(DATE hDate, int newMonth, int newDay, int newYear)
{
    Date* pDate = (Date*)hDate; // casting to the known data type

    if(!dateValidate(newMonth, newDay, newYear))
    {
        printf("Error in date = not changing date\n");
        return 0;
    }

    pDate->month = newMonth;
    pDate->day = newDay;
    pDate->year = newYear;

    return 1;
}

void dateOutput(DATE hDate)
{
    Date* pDate = (Date*)hDate; // casting to the known data type
    
    printf("%2d/%2d/%4d", pDate->month, pDate->day,pDate->year);
}

int dateValidate(int m,int d,int y)
{
    if(m < 1 || m > 12)
    {
        printf("Error in setting month [%d]\n", m);
        return 0;
    }
    if(d < 1 || d > 31) // needs more validation based on month and leap year
    {
        printf("Error is setting day [%d]\n", d);
        return 0;
    }
    if(y < 0)
    {
        printf("Error in setting year [%d]\n", y);
        return 0;
    }

    return 1;
}