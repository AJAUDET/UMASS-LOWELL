#include <stdio.h>

int coin_types[] = {1, 5, 10, 25, 50};

int coins(int change, int index_of_largest_coin);

int main(int argc, char* argv[])
{
    printf("The numebr of ways to make change for 50 cents is %d\n", coins(50, 4));
    return 0;
}

int coins(int change, int index_of_largest_coin)
{
    if(change < 0)
    {
        return 0;
    }
    else if (change == 0)
    {
        return 1;
    }
    else if(index_of_largest_coin == 0)
    {
        return 1;
    }
    return coins(change - coin_types[index_of_largest_coin], index_of_largest_coin) + 
        coins(change, index_of_largest_coin - 1);
}