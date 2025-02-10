#ifndef MY_VECTOR_H
#define MY_VECTOR_H
typedef void* MY_VECTOR;
#include "status.h"

MY_VECTOR my_vector_init_default(void);


// clear the container??

int my_vector_get_size(MY_VECTOR hVector);

int my_vector_get_capacity(MY_VECTOR hVector);

Status my_vetcor_push_back(MY_VECTOR hVector, int value);

Status my_vector_pop_back(MY_VECTOR hVector);

Boolean my_vector_is_empty(MY_VECTOR hVector);


void my_vector_destroy(MY_VECTOR* phVector);

#endif