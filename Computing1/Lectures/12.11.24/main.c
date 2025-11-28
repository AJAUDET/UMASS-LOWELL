#include <stdio.h>
#include <stdlib.h>

enum daysInWeek {Sun = 1, Mon, Tues, Wed, Thurs, Fri, Sat};
typedef enum daysInWeek DIW;

struct point
{
    int x;
    int y;
};
typedef struct point Point;

typedef double Joe;

void outputPoint(Point p);

Point movePoint(Point p, int xOffset);

int main(int argc, char *argv[])
{
    double *pTemps;
    int size = 0;
    double sum;

    // prompt the user to create an array of temperature values and calculate avg
    printf("Please enter how many temperatures you want to enter: ");
    scanf("%d", &size);

    pTemps = malloc(size * sizeof(double));
    if (pTemps == NULL)
    {
        printf("Error allocating memory -- Exiting\n");
        exit(1);
    }

    printf("Please enter %d temperature values followed by ENTER: ", size);
    for (int i = 0; i < size; i++)
    {
        printf("Please enter next value: ");
        scanf("%lf", &pTemps[i]); // old salt version : scanf("%lf", pTemps+i)
        sum += pTemps[i];
    }

    printf("Average temperature is %.1f\n", sum / size);

    free(pTemps);

    // point sample

    Point p1 = {3, 2};

    p1.x = 7;
    outputPoint(p1);

    printf("Moving point by 5 on x axis\n");
    Point p3 = movePoint(p1, 5);
    outputPoint(p3);

    Joe j1;
    j1 = 33.21;

    DIW day = Tues;

    if (day == Tues)
        printf("Yay it is tuesday\n");

    return 0;
}

void outputPoint(Point p)
{
    printf("Point x : %d, y : %d\n", p.x, p.y);
}

Point movePoint(Point p, int xOffset)
{
    Point m;

    m.x = p.x + xOffset;
    m.y = p.y;

    return m;
}