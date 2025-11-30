/*
    Program: queue.h
    Author: AJ Audet
    Date: 3.1.25
    Time spent: 15 mins, it doesn't take too long to write a header file tbh
    Purpose: The purpose of this program is to act as the header file for implementing a queue using linked lists, 
             and to then test the data using the UVA Online Judge for problem 11034
*/

#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_def(void);

// enqueue **
Status queue_enqueue(QUEUE hQ, int data);

// service
Status queue_service(QUEUE hQ);

// front
int* queue_front(QUEUE hQ, Status* pStatus);

// empty **
Boolean queue_is_empty(QUEUE hQ);

// size of
int queue_get_size(QUEUE hQ);

void queue_print(QUEUE hQ);

void queue_destory(QUEUE* phQ);

#endif
