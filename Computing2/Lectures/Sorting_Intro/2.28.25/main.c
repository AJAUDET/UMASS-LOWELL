#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int numbers[], int size, int (*fp_compare)(int, int));
void print_list(int nums[], int size);

void swap(int *a, int *b);

int less_than(int a, int b);
int greater_than(int a, int b);

int prefer_odd(int a, int b);
int prefer_prime(int a, int b);

int is_prime(int num);

int main(int argc, char *argv[])
{
    
    int numbers[] = {3, 6, 9 ,12, 16, 19, 21, 24, 28, 31};

    print_list(numbers, 10);
    printf("****\n");
    bubble_sort(numbers, 10, prefer_odd);
    print_list(numbers, 10);

    return 0;
}

/*

    my def:

    bubble sort is a sorting algorythm that takes an input of an array of numbers and the size of the array
    it compares adjacent elements and if the first is larger than the second they switch places, iterating through the list size - 1 times

    or

    Dr. Adams def:

    bubble sort is a sorting algorythm that takes an input of an array of numbers and the size of the array
    it compares adjacent elements and if the first and second numbers are out of order swap them, iterating through the list size - 1 times

*/
void bubble_sort(int numbers[], int size, int (*fp_compare)(int, int))
{
    int i, j;

    for (i = 0; i < size - 1; i++) // we do this size - 1 times
    {
        for (j = 0; j < size - 1; j++) // we need to stay in bounds with size - 1
        {
            if (fp_compare(numbers[j+1], numbers[j]))
            {
                swap(&numbers[j], &numbers[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_list(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", nums[i]);
    }
}

int less_than(int a, int b)
{
    return a < b;
}

int greater_than(int a, int b)
{
    return a > b;
}

int prefer_odd(int a, int b)
{
    if (a % 2 == b % 2)
    {
        return a < b;
    }

    return a % 2;
}

int prefer_prime(int a, int b)
{
    int a_is_prime = is_prime(a);
    int b_is_prime = is_prime(b);
    if (a_is_prime == b_is_prime)
    {
        return a < b;
    }
    return a_is_prime;
}

int is_prime(int num)
{
    int i;
    if (num < 2)
    {
        return 0;
    }

    for (i = 2; i <= num/2; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}