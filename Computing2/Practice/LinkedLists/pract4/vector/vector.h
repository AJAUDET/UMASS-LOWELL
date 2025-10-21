#ifndef VECTOR_H
#define VECTOR_H

typedef void* VECTOR;

VECTOR vector_init_def(void);

void vector_destroy(VECTOR* phVector);

#endif