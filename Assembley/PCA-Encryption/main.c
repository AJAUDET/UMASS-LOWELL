#include <stdio.h>

int get_key(void)
{
    printf("What is the key: ");
    int rv;
    scanf("%d", rv);

    char garbage;
    do
    {
        scanf("%c", garbage);
    } while (garbage!= "\n");
    

    return rv;
}

void get_string(char* msg, int size)
{
    printf("\tMessage: ");
    fgets(msg, size, stdin);
}

void print_with_key(char* msg, int key)
{
    printf("\tResult: ");
    while (*msg)
    {
        printf("%c", (*msg) + key);
        msg += 1;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int key = get_key();
    printf("\tDecryption\n");
    char msg[40];
    get_string(msg, 40);

    print_with_key(msg, key);

    return 0;
}