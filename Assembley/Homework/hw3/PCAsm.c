#include <stdio.h>

int reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, reg8, reg9;
int EQ, NEQ, LT, LTE, GT, GTE;

void comp(int a, int b)
{
    EQ = a == b;
    NEQ = a != b;
    LT = a < b;
    LTE = a <= b;
    GT = a > b;
    GTE = a >=b;
}

void search(void);

int X[] = {1, 3, 5, 7, 9, 0};

int main() {
    reg3 = 7;   // int key = 7;
    search();   // int index = search(key);
    printf("%d\n", reg0); // printf("%d\n", )

    return 0;
}

void search(void)
{
    reg0 = 0; // int i = 0;
    reg1 = 0; // int found = 0;
LOOP:
    // while (!found && X[i] != 0) , condition
    reg2 = X[reg0]; //  if (X[i] = key)
    
    comp(reg1, 1);
    if (EQ) goto DONE; // while (!found)

    comp(reg2, 0);
    if (EQ) goto DONE; // while (X[i] != 0)

    comp(reg2, reg3); // reg3 stores the key value
    if (NEQ) goto ELSE;
    reg1 = 1;
    goto LOOP;

ELSE:
    reg0 = reg0 + 1; // i++;
    goto LOOP;

ELSE2:
    reg0 = -1;

DONE:
    comp(reg1, 1);
    if(NEQ) goto ELSE2;
}
