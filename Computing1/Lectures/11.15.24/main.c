/*
    Review for Exam 2:
        Pointers: (use, dereferene, address of operators)
            Pass by reference
            Pass pointers and use dereference to modify values
        
        Arrays:
            Functions that use/manipulate arrays
                function that prints an array
                fill an array with specific or random values
                find the index of minimum, maximum, or a specific value
                find first index of adjacent values that sum up to 10
            Make sure you respect the boundaries of the array
        
        Files: 
            open file for reading or writing and check for success (exit otherwise)
            close file
            fprintf
            fscanf :: for numbers/characters
            noc for fscanf

        Memory Diagrams
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    
    printf("X%20dX\n", 123);
    printf("X%-20dX\n", 123);

    int colWidth = 15;
    printf("X%*dX\n",colWidth, 123);

    printf("%+d\n", 123);
    printf("%d\n", -123);



    return 0;
}