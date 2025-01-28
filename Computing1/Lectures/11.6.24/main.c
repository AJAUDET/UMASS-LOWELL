#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int x, noc;
    //printf("Hello Class\n");
    fprintf(stdout, "Hello Class - please enter a number: "); // print somethng to the screen
        // can change output by doing ./a.out > output.txt
    
    //scanf("%d", &x);

    noc = fscanf(stdin,"%d", &x);
    

    if(noc != 1)
        fprintf(stderr, "Error - invalid data\n");

    fprintf(stdout, "You entered %d\n", x);

    // basically have to write in linux for this, ie ./a.out < input.txt > output.txt

    FILE *fptr;

    char fname[] = "numbers.txt";

    fptr = fopen("numbers.txt", "w"); // 3 modes:: "w": write // "a": append // "r": read

    if(fptr == NULL) // could not open file
    {
        printf("Error -- could not open file -- exiting the program\n");
        exit(1);
    }

    for(int i = 0; i < 25; i++)
    {
        fprintf(fptr,"%d\n", i+1);
    }

    fclose(fptr); // releases the rescource so more can be used

    fptr = fopen("numbers.txt", "a"); // 3 modes:: "w": write // "a": append // "r": read

    if(fptr == NULL) // could not open file
    {
        printf("Error -- could not open file -- exiting the program\n");
        exit(1);
    }

    for(int i = 0; i < 25; i++)
    {
        fprintf(fptr,"%d\n", i+1);
    }

    fclose(fptr);

    fptr = fopen(fname, "r");

    if(fptr == NULL) // could not open file
    {
        printf("Error -- could not open file %s -- exiting the program\n", fname);
        exit(1);
    }

    return 0;
}