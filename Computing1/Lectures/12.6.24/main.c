#include <stdio.h>
#include "date.h"

void outputDate(Date d);

int main(int argc, char* argv[])
{
    Date today = {12,31, 2024};
    Date tomorrow = today;
    tomorrow.day += 1;
    tomorrow.month = 99;

    printf("Today is ");
    outputDate(today);

    printf("\nTomorow is ");
    outputDate(tomorrow);
    return 0;
}

void outputDate(Date d)
{
    printf("%d/%d/%d", d.month, d.day, d.year);
}