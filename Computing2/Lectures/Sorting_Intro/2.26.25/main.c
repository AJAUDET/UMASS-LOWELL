#include <stdio.h>

void bubble_sort(int numbers[], int size);

int main(int argc, char* argv[])
{
    //8756242193
    int numbers[] = {8,7,5,6,2,4,1,0,9,3};


    return 0;
}


/*
    bubble sort is a sorting algorythm that takes an input of an array of numbes and the size of the array
    it compares adjacent elements and if the first is larger than teh second tehy switch places
*/
void bubble_sort(int numbers[], int size)
{
    int i, j;

    for(i = 0; i < size - 1; i++) // we do this size - 1 times
    {
        for(j = 0; j < size - 1; j++) // we need to stay in bounds with size - 1
        {
            if(numbers[j] > numbers[j + 1])
            {

            }
        }
    }
}