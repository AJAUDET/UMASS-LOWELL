#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main(int argc, char *argv[])
{

    DATE hToday, hSomeday;

    hToday = dateInitDefault();
    dateOutput(hToday);
    printf("\n");

    dateSet(hToday, 12, 9, 2024);
    dateOutput(hToday);
    printf("\n");

    hSomeday = dateInitDefault();
    dateSet(hSomeday, 2, 21, 3030);
    dateOutput(hSomeday);
    printf("\n");

    printf("\nPlease enter a date (mm/dd/yyyy) : ");
    int m, d, y, noc;
    noc = scanf("%d/%d/%d", &m, &d, &y);

    while (noc != 3 || !dateSet(hSomeday, m, d, y))
    {
        printf("\nPlease enter a date (mm/dd/yyyy) : ");
        noc = scanf("%d/%d/%d", &m, &d, &y);
    }

    dateOutput(hSomeday);
    printf("\n");
    

    dateDestroy(hSomeday);
    dateDestroy(hToday);

    return 0;
}
