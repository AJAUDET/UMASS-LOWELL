#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

GENERIC_VECTOR generic_vector_init_default(void)
{
    return NULL;
}

void generic_vector_destroy(GENERIC_VECTOR* phVector)
{
    printf("destroyification complete\n");
}