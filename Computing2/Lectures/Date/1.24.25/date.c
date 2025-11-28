#include <stdio.h>
#include "date.h"


void output_date(Date date)
{
    printf("%d/%d/%d\n", date.month, date.day, date.year);
}
