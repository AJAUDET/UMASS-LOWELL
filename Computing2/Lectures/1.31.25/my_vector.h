#ifndef MY_VECTOR_H
#define MY_VECTOR_H
typedef void* MY_VECTOR;
#include "status.h"

MY_VECTOR my_vector_init_default(void);

// get or see the numbers
// change the numbers

// remove numbers from the container

// clear the container

//START HERE my_vetcor_push_back();


Boolean my_vector_is_empty(MY_VECTOR hVector);


void my_vector_destroy(MY_VECTOR* phVector);

#endif