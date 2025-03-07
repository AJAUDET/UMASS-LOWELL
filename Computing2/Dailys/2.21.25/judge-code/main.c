#include <stdio.h>
#include <stdlib.h>

struct stack;
typedef struct stack Stack;

struct stack
{
    char data;
    Stack* next;
};

void clearKeyboardBuffer(void);
int compare(char *string);
Stack *stack_pop(Stack *pStack, char *data);
void stack_init_default(Stack *pStack);
Stack *stack_push(Stack **pStack, char data);
int stack_is_empty(Stack *pStack);
int check_complete(char left, char right);



int main(int argc, char *argv[])
{
    char string[256];
    int i;
    int tests;

    scanf("%d", &tests);
    clearKeyboardBuffer();

    for (i = 0; i < tests; i++)
    {
        fgets(string, sizeof string, stdin);

        if (compare(string))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

void clearKeyboardBuffer(void)
{
    char c = 'a';
    while (c != '\n')
    {
        scanf("%c", &c);
    }
}

void stack_init_default(Stack *pStack)
{
    pStack = NULL;
}

Stack *stack_push(Stack **pStack, char data)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    if (temp == NULL)
    {
        printf("Failed");
        exit(1);
    }

    temp->data = data;
    temp->next = *pStack;
    *pStack = temp;

    return *pStack;
}

Stack *stack_pop(Stack *pStack, char *data)
{
    Stack *temp = pStack;
    *data = temp->data;
    pStack = pStack->next;

    free(temp);
    return pStack;
}

int stack_is_empty(Stack *pStack)
{
    return pStack == NULL ? 1 : 0;
}

int check_complete(char left, char right)
{
    if (left == '[' && right == ']')
    {
        return 1;
    }
    else if (left == '(' && right == ')')
    {
        return 1;
    }
    else if (left == '{' && right == '}')
    {
        return 1;
    }

    return 0;
}

int compare(char *string)
{
    int i = 0;
    char test_chr;
    Stack *test = NULL;
    stack_init_default(test);
    while (string[i])
    {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{')
        {
            stack_push(&test, string[i]);
        }

        if (string[i] == ')' || string[i] == ']' || string[i] == '}')
        {
            if (stack_is_empty(test))
            {
                return 0;
            }
            else
            {
                test = stack_pop(test, &test_chr);
                if (!check_complete(test_chr, string[i]))
                {
                    return 0;
                }
            }
        }

        i++;
    }
    if(test == NULL)
    {
        return 1;
    }
    return 0;
}