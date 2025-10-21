#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {false, true} bool;

void bubbleSort(int arr[], int size);
void myIntSwap(int *px, int *py);

const int ARR_SIZE = 100;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int numbers[ARR_SIZE];

    printf("Unsorted Array: \n");
    for(int i = 0; i < ARR_SIZE; i++)
    {
        numbers[i] = rand() % 101;
        printf("%10d\t\t", numbers[i]);
    }

    printf("\n\nSorted Array: \n");
    
    bubbleSort(numbers, ARR_SIZE);

    for(int i = 0; i < ARR_SIZE; i++)
    {
        printf("%10d\t\t", numbers[i]);
    }

    return 0;
}

void myIntSwap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

void bubbleSort(int arr[], int size)
{
    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        for(int i = 0; i < size - 1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                myIntSwap(&arr[i], &arr[i+1]);
                swapped = true;
            }
        }
    }
}