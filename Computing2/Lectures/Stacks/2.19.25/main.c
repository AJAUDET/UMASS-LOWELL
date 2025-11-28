#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int test_case_is_valid(void);
void clearKeyboardBuffer(void);

int main(int argc, char *argv[])
{
    
    int n;
    int i;
    scanf("%d", &n);
    clearKeyboardBuffer();
    fprintf(stderr, "this is to stderr\n");

    for(i = 0; i < n; i++)
    {
        if(test_case_is_valid())
        {
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }



    /*
    STACK hStack;

    hStack = stack_init_default();
    if (hStack == NULL)
    {
        printf("Failed to allocate space for stack\n");
        exit(1);
    }

    // work

    for (int i = 0;i < 10; i++)
    {
        if (stack_push(hStack, i) == NULL)
        {
            printf("that didnt work, %d\n", i);
            exit(1);
        }
    }

    while (!stack_is_empty(hStack))
    {
        printf("top of stack b4 p0pp1n is %d : ", stack_top(hStack, NULL));
        stack_pop(hStack);
        printf("pop!\n");
    }

    stack_destroy(&hStack);
    */

    return 0;
}

int test_case_is_valid(void)
{
    char c;
    int noc;
    noc = scanf("%c", &c);
    while(noc == 1 && c != '\n')
    {
        noc = scanf("%c", &c);
    }
    return 1;
}

void clearKeyboardBuffer(void)
{
    char c = 'a';
    while(c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}