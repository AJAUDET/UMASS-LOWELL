/*
    heapsort: heapify the array, removing the max n - 1 times
    heapify: calling fix down on every element starting from the back, ignoring leaf nodes
*/

#include <stdio.h>
#include <stdlib.h>

void heap_insert(int heap[], int *pSize, int value);
void fix_up(int heap[], int index);
void heap_remove_max(int heap[], int *pSize);
void fix_down(int heap[], int size, int index);

int main(int argc, char *argv[])
{
    // 8,7,1,2,9,6,5,3,4,0

    int heap[50];
    int size = 0;
    int i;

    heap_insert(heap, &size, 8);
    heap_insert(heap, &size, 7);
    heap_insert(heap, &size, 1);
    heap_insert(heap, &size, 2);
    heap_insert(heap, &size, 9);
    heap_insert(heap, &size, 6);
    heap_insert(heap, &size, 5);
    heap_insert(heap, &size, 3);
    heap_insert(heap, &size, 4);
    heap_insert(heap, &size, 0);

    while(size > 0)
    {
        // printf("%d\n", heap[0]);
        heap_remove_max(heap,&size);
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", heap[i]);
    }

    return 0;
}

void heap_insert(int heap[], int *pSize, int value)
{
    if (*pSize >= 50)
    {
        printf("Heap is full...crashing\n");
        exit(1);
    }

    heap[*pSize] = value;
    (*pSize)++;

    fix_up(heap, *pSize - 1);
}

void fix_up(int heap[], int index)
{
    int index_of_parent = (index - 1) / 2;
    int temp;

    if (index > 0)
    {
        if (heap[index] > heap[index_of_parent])
        {
            temp = heap[index];
            heap[index] = heap[index_of_parent];
            heap[index_of_parent] = temp;
            fix_up(heap, index_of_parent);
        }
    }
}

void heap_remove_max(int heap[], int *pSize)
{
    int temp;
    temp = heap[0];
    heap[0] = heap[*pSize - 1];
    heap[*pSize - 1] = temp;

    (*pSize)--;
    fix_down(heap, *pSize, 0);
}

void fix_down(int heap[], int size, int index)
{
    int index_of_left_child = 2 * index + 1;
    int index_of_right_child = 2 * index + 2;
    int index_of_largest_child;
    int temp;

    if (index_of_left_child < size) // i have at least one child
    {
        if (index_of_right_child < size) // i have 2 children
        {
            index_of_largest_child = (heap[index_of_left_child] > heap[index_of_right_child]) ? index_of_left_child : index_of_right_child;
        }
        else // only one child
        {
            index_of_largest_child = index_of_left_child;
        }

        if(heap[index] < heap[index_of_largest_child])
        {
            temp = heap[index];
            heap[index] = heap[index_of_largest_child];
            heap[index_of_largest_child] = temp;

            fix_down(heap, size, index_of_largest_child);
        }
    }
}
