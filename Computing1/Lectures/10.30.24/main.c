#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int array[], int value, int size);
void outputArray(int *array, int size);
int arraySum(int array[], int size);

// the char array must be valid and allocated
char *modifyChar(char str[], int size, char newChar, int pos);

int main(int argc, char *argv[])
{
    srand(time(NULL));

    printf("Time is %d", time(NULL));
    printf("%d\n", RAND_MAX);

    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", rand());
    }

    char *myArgv[2] = {"abc", "defgh"};

    char name[] = "Firstname Lastname";

    printf("%s\n", myArgv[1]);

    printf("%c\n", "ABCDEFG"[4]);     // general derefrence to the letter at the index : 4
    printf("%c\n", *("ABCDEFG" + 4)); // general derefrence to the letter at the adress : 4

    int numbers[20];

    initArray(numbers, 1, 20);
    numbers[12] = 12;
    outputArray(numbers, 20);

    printf("Sum of numbers is %d\n", arraySum(numbers, 20));

    printf("name %s\n ", name);
    printf("modified name %s\n", modifyChar(name, sizeof(name), 'X', 2));

    printf("modified name %s\n", modifyChar(name, sizeof(name), 'X', 30));
    printf("modified name %s\n", modifyChar(name, sizeof(name), 'X', sizeof(name) - 1));

    return 0;
}

void initArray(int array[], int value, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = value;
    }
}

void outputArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("array[%d] is %d\n", i, *(array + i)); // same as arr[i]
    }
}

int arraySum(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

// precondition: str is a valid C-string with a defined size
//               pos has to be valid (0 to size -1), cant be negative
// post conditin: char at pos has been replaced
char *modifyChar(char str[], int size, char newChar, int pos)
{
    if (pos < 0 || pos > size - 2)
    {
        printf("Error not modifying string\n");
        return str;
    }

    str[pos] = newChar;

    return str;
}