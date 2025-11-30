#include <stdio.h>

int main(int argc, char* argv[])
{
    int num = 3;

    if(num != 0) goto ELSE;

    printf("This is 0\n");
    goto END;

ELSE:
    printf("this isnt 0\n");
END:

/*
    if(num == 0)
    {
        printf("This is 0\n");
    }
    else
    {
        printf("This isnt 0\n");
    }
*/

    return 0;
}