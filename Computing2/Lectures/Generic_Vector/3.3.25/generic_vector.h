#ifndef GEN_VECTOR_H
#define GEN_VECTOR_H

typedef void* GENERIC_VECTOR;

GENERIC_VECTOR generic_vector_init_default(void);

void generic_vector_destroy(GENERIC_VECTOR* phVector);

#endif