#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RUNS 1000000 // macro, == const int RUNS = 100;
// the macro searches and replaces before

enum door
{
    DOOR1 = 1,
    DOOR2,
    DOOR3
};
typedef enum door Door;

typedef enum
{
    FALSE,
    TRUE
} bool;

Door pickRandomDoor(void);

int runSimulation(bool userIsSwitchingDoor);

void testRandomDoor(void);

int main(int argc, char *argv[])
{
    bool isSwitching = FALSE;
    int wins;

    wins = runSimulation(isSwitching);
    printf("When user is not switching doors: %.2f%%\n", 100 * (double)wins / RUNS);

    isSwitching = TRUE;
    wins = runSimulation(isSwitching);
    printf("When user is switching doors: %.2f%%\n", 100 * (double)wins / RUNS);

    // testRandomDoor();

    return 0;
}

Door pickRandomDoor(void)
{
   /* double r = 3 * (double)rand() / RAND_MAX; // 0...1

    return r;
    */

    return (Door) (1 + rand() % 3);
}

int runSimulation(bool userIsSwitchingDoor)
{
    Door carDoor;
    Door playerDoor;

    int wins = 0;

    srand(time(0));

    for (int i = 0; i < RUNS; i++)
    {
        carDoor = pickRandomDoor();
        playerDoor = pickRandomDoor();

        if (!userIsSwitchingDoor)
        {
            if (carDoor == playerDoor)
            {
                wins++;
            }
        }
        else
        {
            if (carDoor != playerDoor)
            {
                wins++;
            }
        }
    }

    return wins;
}

void testRandomDoor(void)
{
    int d1 = 0, d2 = 0, d3 = 0, d;
    for(int i = 0; i < RUNS; i++)
    {
        d = pickRandomDoor();
        switch (d)
        {
        case 1:
            d1++;
            break;
        case 2:
            d2++;
            break;
        case 3:
            d3++;
            break;
        default:
            break;
        }
    }

    printf("d1 %d d2 %d d3 %d // sums: %d\n", d1, d2, d3, d1+d2+d3);
}