#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    STACK hStack;

    hStack = stack_init_default();
    if (hStack == NULL)
    {
        printf("Failed to allocate space for stack\n");
        exit(1);
    }

    // work

    for (int i = 0;i < 10; i++)
    {
        if (stack_push(hStack, i) == NULL)
        {
            printf("that didnt work, %d\n", i);
            exit(1);
        }
    }

    while (!stack_is_empty(hStack))
    {
        printf("top of stack b4 p0pp1n is %d : ", stack_top(hStack, NULL));
        stack_pop(hStack);
        printf("pop!\n");
    }

    stack_destroy(&hStack);
    return 0;
}