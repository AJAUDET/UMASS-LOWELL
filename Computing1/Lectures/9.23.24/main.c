#include <stdio.h>

void joe(int number);

void towers(int disc, int from, int to, int spare);

int count;

int main(int argc, char* argv[])
{
    int x = 3;
    count = 0;
    // joe(x);

    towers(8, 1, 2, 3);
    return 0;
}

void joe(int number)
{
    if(number > -4)
    {
        printf("Joe says the number is %d\n", number);
        joe(number-1);
    }
    return;
}

void towers(int disc, int from, int to, int spare)
{
    count++;
    if(disc > 0)
    {
        //move disk to spare
        towers(disc-1,from, spare, to);
        //move my disk
        if(disc == 8)
        {
            printf("%d count : Moving disk %d from %d to %d\n", count, disc, from, to);
        }
        //move disc from spare to where i am now
        towers(disc-1,spare, to, from);
    }
    return;
}