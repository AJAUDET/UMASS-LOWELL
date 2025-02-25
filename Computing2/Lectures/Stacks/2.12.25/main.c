#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char* argv[])
{
    STACK hStack;

    hStack = stack_init_default();
    if(hStack == NULL)
    {
        printf("Failed to allocate space for stack\n");
        exit(1);
    }

    // work

    stack_destroy(&hStack);
    return 0;
}