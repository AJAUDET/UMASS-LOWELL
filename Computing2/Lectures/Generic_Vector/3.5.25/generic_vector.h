#ifndef GEN_VECTOR_H
#define GEN_VECTOR_H
#include "generic.h"
#include "status.h"

typedef void *GENERIC_VECTOR;

GENERIC_VECTOR generic_vector_init_default(ITEM (*fp_init_copy)(ITEM hItem), void (*fp_destroy)(ITEM *phItem));

// push back ** 
Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM value);

// pop back

// at

// is empty **
Boolean generic_vector_is_empty(GENERIC_VECTOR hVector);

// get size ** 
int generic_vector_get_size(GENERIC_VECTOR hVector);

// get capacity ** 
int generic_vector_get_capacity(GENERIC_VECTOR hVector);

void generic_vector_destroy(GENERIC_VECTOR *phVector);

#endif