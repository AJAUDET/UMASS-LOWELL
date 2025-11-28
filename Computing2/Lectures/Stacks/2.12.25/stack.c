#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK stack_init_default(void)
{
    return NULL;
}

void stack_destroy(STACK *phStack)
{
    printf("destroyification complete\n");
}