#include <stdio.h>

struct node; // forward declaration
typedef struct node Node;

struct node
{
    int value;
    Node* next;
};

void output_list(Node* head);
void recursive_output_list(Node* head);


int main(int argc, char* argv[])
{
    //42, 107, 36

    Node* head;
    head = (Node*)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("Could not allocate space for head node\n");
        exit(1);
    }

    head->value = 42;
    head->next = (Node*)malloc(sizeof(Node));
    if(head->next == NULL)
    {
        printf("Could not allocate space for next node\n");
        exit(1);
    }
    head->next->value = 107;
    head->next->next = (Node*)malloc(sizeof(Node));
    if(head->next->next == NULL)
    {
        printf("Could not allocate space for next node\n");
        exit(1);
    }
    head->next->value = 36;
    head->next->next = NULL;



    return 0;
}