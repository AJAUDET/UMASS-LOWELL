#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

long long int num_of_assignments;
long long int num_of_compairisons;

void print_array(int numbers[], int size);

void vanilla_bubble_sort(int numbers[], int size); // 100 000 in 24 blinks :: n^2 alg
void bubble_sort(int numbers[], int size);         // 100 000 in 20 blinks (0 if initially sorted)

void instrumented_bubble_sort(int numbers[], int size);
/*
    Bubble Sort
    Done! 150676884 100019218
*/

void selection_sort(int numbers[], int size); // 100 000 in 5 blinks :: n^2 alg
void instrumented_selection_sort(int numbers[], int size);
/*
    Selection sort
    Done! 50142362 100029997
*/


void vanila_insertion_sort(int numbers[], int size);        // 100 000 in 6 blinks :: n^2 alg
void insertion_sort_with_shifting(int numbers[], int size); // 100 000 in 5 blinks
void insertion_sort(int numbers[], int size);               // 100 000 in 4 blinks

void shell_sort(int numbers[], int size); // 100 000 in 0 :: 1 000 000 in 0 :: 10 000 000 in 6 blinks :: idk its a fucked up and evil alg
void instrumented_shell_sort(int numbers[], int size);
/*
    Shell sort
    Done! 718787 601870
*/

void heap_sort(int numbers[], int size); // 100 000 in 0 :: 1 000 000 in .5 :: 10 000 000 in 4 blinks :: nlog(n) alg

void quick_sort(int numbers[], int size); // 100,000 in 0 :: 10 000 000 in 3 blinks
void instrumented_quick_sort(int numbers[], int size); 

void my_swap(int *a, int *b);
void instrumented_my_swap(int *a, int *b);

int find_index_of_min(int array[], int size, int starting_index);
int instrumented_find_index_of_min(int array[], int size, int starting_index);
void heapify(int numbers[], int size);
void fix_down(int heap[], int size, int index);
void heap_remove_max(int heap[], int *pSize);

void copy_array(int numbers[], int backup[], int size);

int main(int argc, char *argv[])
{
    int *numbers;
    int *backup;
    int i;

    numbers = (int *)malloc(sizeof(int) * SIZE);
    backup = (int *)malloc(sizeof(int) * SIZE);
    if (numbers == NULL || backup == NULL)
    {
        printf("Failed to allocate space\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++)
    {
        numbers[i] = (rand() << 15) + rand();
        // numbers[i] = i;
    }
    copy_array(numbers, backup, SIZE);

    num_of_assignments = 0;
    num_of_compairisons = 0;

    /*
        printf("Bubble Sort\n");
        instrumented_bubble_sort(numbers, SIZE);
        printf("Done! %lld %lld\n", num_of_assignments, num_of_compairisons);
    
        printf("Selection Sort\n");
        selection_sort(numbers, SIZE);
        printf("Done!\n");


        printf("Insertion Sort\n");
        insertion_sort(numbers, SIZE);
        printf("Done!\n");


        printf("Shell Sort\n");
        shell_sort(numbers, SIZE);
        printf("Done!\n");

    printf("Heap Sort\n");
    heap_sort(numbers, SIZE);
    printf("Done!\n");
    
    printf("Quick Sort\n");
    quick_sort(numbers, SIZE);
    printf("Done!\n");
    */

    printf("Shell sort\n");
    instrumented_shell_sort(numbers,SIZE);
    printf("Done! %lld %lld\n", num_of_assignments, num_of_compairisons);
    printf("quick sort\n");
    instrumented_quick_sort(backup, SIZE);
    printf("Done! %lld %lld\n", num_of_assignments, num_of_compairisons);
    copy_array(numbers, backup, SIZE);

    // print_array(numbers, SIZE);

    free(numbers);
    return 0;
}

void print_array(int numbers[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\n", numbers[i]);
    }
}

void vanilla_bubble_sort(int numbers[], int size)
{
    int i;
    int j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                my_swap(numbers + j, numbers + j + 1);
            }
        }
    }
}

void bubble_sort(int numbers[], int size)
{
    /*
        Starting from the beginning of a list compare adjacent pairs,
        if they are out of order swap them, do this for the entire list n-1 times.
    */
    int i;
    int j;
    int swapped_something;

    for (i = 0; i < size - 1; i++)
    {
        swapped_something = 0;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                my_swap(numbers + j, numbers + j + 1);
                swapped_something = 1;
            }
        }
        if (!swapped_something)
        {
            break;
        }
    }
}

void my_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int numbers[], int size)
{
    // find the smallest element starting from i and swap it into position i
    // do this n - 1 tiems with i getting bigger each time

    /*
        The smallest element is selected from a list and swapped with the leftmost element,
        and that element becomes a part of the sorted array.
        This process continues, swapping the smallest element found in the unsorted list to the end of the sorted list, do this n-1 times.
    */

    int i;
    for (i = 0; i < size - 1; i++)
    {
        my_swap(&numbers[i], &numbers[find_index_of_min(numbers, size, i)]);
    }
}

int find_index_of_min(int array[], int size, int starting_index)
{
    int index_of_min = starting_index;
    int i;

    for (i = starting_index; i < size; i++)
    {
        if (array[i] < array[index_of_min])
        {
            index_of_min = i;
        }
    }
    return index_of_min;
}

void vanila_insertion_sort(int numbers[], int size)
{
    int i;
    int j;
    int temp;
    for (i = 1; i < size; i++)
    {
        j = i;
        while (j > 0 && numbers[j] < numbers[j - 1])
        {
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            j--;
        }
    }
}

void insertion_sort_with_shifting(int numbers[], int size)
{
    int i;
    int j;
    int temp;
    for (i = 1; i < size; i++)
    {
        j = i;
        temp = numbers[j];
        while (j > 0 && temp < numbers[j - 1])
        {
            numbers[j] = numbers[j - 1];
            j--;
        }
        numbers[j] = temp;
    }
}

void insertion_sort(int numbers[], int size)
{
    /*
        Assume first item in the list is a sorted list,
        take the element in the unsorted list that is adjacent to the sorted list and swap it into the correct position in the sorted list,
        doing this n-1 times.
    */
    int i;
    int j;
    int temp;

    // sentinel improvement
    my_swap(&numbers[0], &numbers[find_index_of_min(numbers, size, 0)]);

    for (i = 2; i < size; i++)
    {
        j = i;
        temp = numbers[j];
        while (temp < numbers[j - 1])
        {
            numbers[j] = numbers[j - 1];
            j--;
        }
        numbers[j] = temp;
    }
}

void shell_sort(int numbers[], int size)
{
    /*
        h-sort the list with decreasing values of h,
        unitl and including h == 1
    */

    // select an h value
    int h = 2;
    int i;
    int j;
    int temp;

    while (h < size / 3)
    {
        h *= 2;
    }
    h = h - 1;

    while (h > 0)
    {
        for (i = h; i < size; i++)
        {
            j = i;
            temp = numbers[j];
            while (j >= h && temp < numbers[j - h])
            {
                numbers[j] = numbers[j - h];
                j -= h;
            }
            numbers[j] = temp;
        }
        h /= 2;
    }
}

void heap_sort(int numbers[], int size)
{
    // heapify the array
    // remove the max n - 1 times
    int i;
    int number_of_iterations = size - 1;

    heapify(numbers, size);

    for (i = 0; i < number_of_iterations; i++)
    {
        heap_remove_max(numbers, &size);
    }
}

void heapify(int numbers[], int size)
{
    // heapify: call fix down on every element in the array, starting from the back, ignoring leaf nodes
    int i;
    for (i = (size / 2) - 1; i >= 0; i--)
    {
        fix_down(numbers, size, i);
    }
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

        if (heap[index] < heap[index_of_largest_child])
        {
            temp = heap[index];
            heap[index] = heap[index_of_largest_child];
            heap[index_of_largest_child] = temp;

            fix_down(heap, size, index_of_largest_child);
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

void quick_sort(int numbers[], int size)
{
    // select a pivot
    int temp;

    int index_of_right = size - 1;
    int index_of_left = 0;

    if (size > 1)
    {
        while (index_of_left < index_of_right)
        {
            // scan from right
            while (index_of_left < index_of_right && numbers[index_of_right] >= numbers[0])
            {
                index_of_right--;
            }
            // scan from left
            while (index_of_left < index_of_right && numbers[index_of_left] <= numbers[0])
            {
                index_of_left++;
            }

            if (index_of_left < index_of_right)
            {
                temp = numbers[index_of_left];
                numbers[index_of_left] = numbers[index_of_right];
                numbers[index_of_right] = temp;
            }
        }
        // swap the pivot into the place where the scanners met
        temp = numbers[0];
        numbers[0] = numbers[index_of_left];
        numbers[index_of_left] = temp;

        // quicksort the left
        if (index_of_left > 1)
        {
            quick_sort(numbers, index_of_left);
        }

        // quicksort the right
        if (size - index_of_left - 1 > 1)
        {
            quick_sort(numbers + index_of_left + 1, size - index_of_left - 1);
        }
    }
}

void instrumented_bubble_sort(int numbers[], int size)
{
    int i;
    int j;
    int swapped_something;

    num_of_assignments++; // init i
    for (i = 0; i < size - 1; i++)
    {
        num_of_compairisons++; // condition
        swapped_something = 0;
        num_of_assignments++; // swapped something
        num_of_assignments++; // init of j
        for (j = 0; j < size - 1 - i; j++)
        {
            num_of_compairisons++; // condition
            num_of_compairisons++; // if cond
            if (numbers[j] > numbers[j + 1])
            {
                instrumented_my_swap(numbers + j, numbers + j + 1);
                swapped_something = 1;
                num_of_assignments++; // swapped assignment
            }
            num_of_assignments++; // incriment of j
        }
        num_of_compairisons++; // last condition for j
        num_of_compairisons++; // if statement
        if (!swapped_something)
        {
            break;
        }
        num_of_assignments++; // incriment of i
    }
    num_of_compairisons++; // last condition
}

void instrumented_my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    num_of_assignments += 3;
}

void copy_array(int numbers[], int backup[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        backup[i] = numbers[i];
    }
}

void instrumented_selection_sort(int numbers[], int size)
{
    int i;
    num_of_assignments++; // init
    for (i = 0; i < size - 1; i++)
    {
        num_of_compairisons++; // comparison
        instrumented_my_swap(&numbers[i], &numbers[instrumented_find_index_of_min(numbers, size, i)]);
        num_of_assignments++; // incriemnt
    }
    num_of_compairisons++; // last comparison
}

int instrumented_find_index_of_min(int array[], int size, int starting_index)
{
    int index_of_min = starting_index;
    int i;
    num_of_assignments++; // init
    num_of_assignments++; // init for i
    for (i = starting_index; i < size; i++)
    {
        num_of_compairisons++; // cond
        num_of_compairisons++; // if statement
        if (array[i] < array[index_of_min])
        {
            index_of_min = i;
            num_of_assignments++; // index
        }
        num_of_assignments++; // incriment
    }
    num_of_compairisons++; // last cond
    return index_of_min;
}

void instrumented_shell_sort(int numbers[], int size)
{
    int h = 2;
    int i;
    int j;
    int temp;

    num_of_assignments++; // init
    while (h < size / 3)
    {
        num_of_compairisons++; // cond
        h *= 2;
        num_of_assignments++; // assignment
    }
    num_of_compairisons++; // last cond
    h = h - 1;
    num_of_assignments++; // assign

    while (h > 0)
    {
        num_of_compairisons++;//cond
        num_of_assignments++; // init
        for (i = h; i < size; i++)
        {
            num_of_compairisons++; // cond
            j = i;
            temp = numbers[j];
            num_of_assignments+=2; // j and temp
            while (j >= h && temp < numbers[j - h])
            {
                num_of_compairisons+=2; // conds
                numbers[j] = numbers[j - h];
                j -= h;
                num_of_assignments+=2; // numbers[j] and j
            }
            if(j < h)
            {
                num_of_compairisons++;
            }
            else
            {
                num_of_compairisons +=2;
            }

            numbers[j] = temp;
            num_of_assignments++; // numbers[j]
            num_of_assignments++; // incriment
        }
        num_of_compairisons++; // last cond
        h /= 2;
        num_of_assignments++; // h
    }
    num_of_compairisons++; // last cond
}

void instrumented_quick_sort(int numbers[], int size)
{
   
    int temp;
    int index_of_right = size - 1;
    int index_of_left = 0;

     // select a pivot...
    int candidate_index = ((rand()<<15) + rand()) % size;
    temp = numbers[0];
    numbers[0] = numbers[candidate_index];
    numbers[candidate_index] = temp; 

    num_of_assignments+=6; // init stuff

    num_of_compairisons++; // cond
    if (size > 1)
    {
        while (index_of_left < index_of_right)
        {
            num_of_compairisons++; // cond
            // scan from right
            while (index_of_left < index_of_right && numbers[index_of_right] >= numbers[0])
            {
                num_of_compairisons+=2;
                index_of_right--;
                num_of_assignments++;
            }
            if(index_of_left >= index_of_right)
            {
                num_of_compairisons++;
            }
            else{
                num_of_compairisons+=2;
            }
            num_of_compairisons++; // last cond

            // scan from left
            while (index_of_left < index_of_right && numbers[index_of_left] <= numbers[0])
            {
                num_of_compairisons+=2;
                index_of_left++;
                num_of_assignments++;
            }
            if(index_of_left >= index_of_right)
            {
                num_of_compairisons++;
            }
            else{
                num_of_compairisons+=2;
            }

            num_of_compairisons++;
            if (index_of_left < index_of_right)
            {
                temp = numbers[index_of_left];
                numbers[index_of_left] = numbers[index_of_right];
                numbers[index_of_right] = temp;
                num_of_assignments+=3;
            }
        }
        num_of_compairisons++;

        // swap the pivot into the place where the scanners met
        temp = numbers[0];
        numbers[0] = numbers[index_of_left];
        numbers[index_of_left] = temp;
        num_of_assignments+=3;

        // quicksort the left
        num_of_compairisons++;
        if (index_of_left > 1)
        {
            instrumented_quick_sort(numbers, index_of_left);
        }
        
        num_of_compairisons++;
        // quicksort the right
        if (size - index_of_left - 1 > 1)
        {
           instrumented_quick_sort(numbers + index_of_left + 1, size - index_of_left - 1);
        }
    }
}
