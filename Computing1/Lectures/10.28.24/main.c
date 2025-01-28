#include <stdio.h>

void outputArray(int array[], int size);

int main(int argc, char* argv[]) // argv is an array of pointers to characters
{
    int numbers[] = {1,2,3,4,5,6,7,8};
    int moreNumbers[15];
        // first index of any array is 0
        // largest index in any array is size - 1;

    printf("numbers is %p, *numbers is %d\n", numbers, *numbers);

    for(int i = 0; i < 12; i++)
    {
        //printf("numbers[%d] is %d\n", i, numbers[i]); // general dereference
        printf("numbers[%d] is %d\n", i, *(numbers+i)); // pointer arithmatic then dereference
    }

    printf("sizeof(numbers) is %lu\n", sizeof(numbers)); // size in bytes
    printf("sizeof(int) is %lu\n", sizeof(int));

    printf("The array has a sizeof %lu\n", sizeof(numbers)/sizeof(numbers[0]));

    for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        printf("numbers[%d] is %d\n", i, numbers[i]);
    }

    printf("initializing array\n");
    for(int i = 0; i < 15; i++)
    {
        printf("moreNumbers[%d] is %d\n", i, moreNumbers[i]);
        moreNumbers[i] = 0;
    }

    printf("initialized array\n");
    for(int i = 0; i < 15; i++)
    {
        printf("moreNumbers[%d] is %d\n", i, moreNumbers[i]);
    }

    printf("Output nums \n");
    outputArray(numbers, sizeof(numbers)/sizeof(numbers[0]));

    // character arrays (strings)
    char word[] = {'T','R','U', 'C','K'}; // no null terminator
    char newWord[] ={'T','R','U', 'C','K','\0'}; // has NULL terminator
    char word3 = "TRUCK"; // c-string -- it is NULL terminated automatically

    printf("word[2] is %c\n", word[2]);

    printf("word is %s\n", word);
    printf("newWord is %s\n", newWord);

    printf("argc is %d argv[0] is %s", argc, argv[0]);

    printf("word3 is %s\n", word3);
    printf("sizeof(word3) is %lu", sizeof(word3));
    
    return 0;
}

// when we pass arrays to functions we need to pass the size
void outputArray(int array[], int size)
{
    printf("sizeof(array) is %lu\n", sizeof(array));
    for(int i = 0; i < size ; i++)
    {
        printf("array[%d] is %d\n", i, array[i]);
    }  
}