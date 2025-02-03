#include <stdio.h>

int main(int argc, char* argv[])
{
    // create a variable to store text
    char songs[100];

    // create a file pointer and have it open the file in append mode
        // w : write, a : append, r : read
    FILE *fptr;
    fptr = fopen("songs.txt", "a");

    printf("What song do you want to add to the file: ");
    // use fgets to read the whole line of the sting in the array
        // stdin : standard input for whole line reading
    fgets(songs, 100, stdin);

    // use fprintf(fptr, "") to append the text to the file
    fprintf(fptr, "%s", songs);
    
    // close the file
    fclose(fptr);
    return 0;
}