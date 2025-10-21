#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void myIntSwap(int *px, int *py);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

#define RUNS 300

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int arr[RUNS];

    for(int i = 0; i < RUNS; i++)
    {
        arr[i] = rand() % 201;
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void myIntSwap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            myIntSwap(&arr[i], &arr[j]);
        }
    }
    myIntSwap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int part = partition(arr, low, high);
        quickSort(arr, low , part - 1);
        quickSort(arr, part + 1, high);
    }
}