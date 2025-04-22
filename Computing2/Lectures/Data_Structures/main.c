#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int value;
    Node *left;
    Node *right;
};

Node *tree_insert(Node *root, int value);
void reference_tree_insert(Node **pRoot, int value);

void print_in_order_traversal(Node* root);

void tree_destroy(Node* root);

int main(int argc, char *argv[])
{
    Node *root = NULL;

    // 1,7,3,4,8,0,6,2,5,9

    root = tree_insert(root,1);
    root = tree_insert(root,7);
    root = tree_insert(root,3);
    root = tree_insert(root,4);
    root = tree_insert(root,8);
    root = tree_insert(root,0);
    root = tree_insert(root,6);
    root = tree_insert(root,2);
    root = tree_insert(root,5);
    root = tree_insert(root,9);

    /*
    reference_tree_insert(&root, 1);
    reference_tree_insert(&root, 7);
    reference_tree_insert(&root, 3);
    reference_tree_insert(&root, 4);
    reference_tree_insert(&root, 8);
    reference_tree_insert(&root, 0);
    reference_tree_insert(&root, 6);
    reference_tree_insert(&root, 2);
    reference_tree_insert(&root, 5);
    reference_tree_insert(&root, 9);
    */
   
    print_in_order_traversal(root);

    return 0;
}

Node *tree_insert(Node *root, int value)
{
    if(root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        if(root == NULL)
        {
            printf("Failed to allocate space for %d\n",value);
            exit(1);
        }
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    }
    else if (value < root->value)
    {
        root->left = tree_insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = tree_insert(root->right, value);
    }
    else
    {
        ;
    }
    return root;
}

void reference_tree_insert(Node **pRoot, int value)
{
    if (*pRoot == NULL)
    {
        *pRoot = (Node *)malloc(sizeof(Node));
        if (*pRoot == NULL)
        {
            printf("Failed to allocate space for Node containing %d\n", value);
            exit(1);
        }
        (*pRoot)->value = value;
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
    }
    else if (value < (*pRoot)->value)
    {
        reference_tree_insert(&((*pRoot)->left), value);
    }
    else if(value > (*pRoot)->value)
    {
        reference_tree_insert(&((*pRoot)->right), value);
    }
    else
    {
        ;// they r the same...ignore it, we are building a set
    }
}

void print_in_order_traversal(Node* root)
{
    // LSR -- in order traversal
    if(root != NULL)
    {
        print_in_order_traversal(root->left);
        printf("%d\n",root->value);
        print_in_order_traversal(root->right);
    }
}

void tree_destroy(Node* root)
{
    // LRS -- post order traversal
    if(root != NULL)
    {
        tree_destroy(root->left);
        tree_destroy(root->right);
        free(root);
    }
}
