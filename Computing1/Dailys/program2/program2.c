/*
    Program Name: program2.c
    Author: AJ Audet
    Date of Beginning: November 11 2024
    Date of Completion: November 11 2024
    Purpose: The purpose of this program is to simulate the fibonacci sequence given a number to find out how much "Green Crud"
             there will be @ the end of the sequence, sequence is sumilated by Fn = fn-1 + fn-2 for n > 1
    Time Spent: 30 minutes
*/

#include <stdio.h>

int getAmmountOfCrud(void);
int getDays(void);
void fibonacciSequence(int crud, int days);
void clearKeyboardBuffer(void);
int userWishesToContinue(void);

int main(int argc, char *argv[])
{
    int crud, days;

    do
    {
        crud = getAmmountOfCrud();
        days = getDays();

        fibonacciSequence(crud, days);
    } while (userWishesToContinue());

    return 0;
}

int getAmmountOfCrud(void)
{
    int noc, input;

    printf("How many pounds of crud do you have: ");

    noc = scanf("%d", &input);
    clearKeyboardBuffer();
    while ((input < 0) || noc != 1)
    {
        printf("Please enter a valid ammount of crud: ");
        noc = scanf("%d", &input);
        clearKeyboardBuffer();
    }
    return input;
}

int getDays(void)
{
    int noc, input;

    printf("How many days do you want to wait: ");
    noc = scanf("%d", &input);
    clearKeyboardBuffer();
    while ((input < 0) || noc != 1)
    {
        printf("Please enter a valid ammount of days: ");
        noc = scanf("%d", &input);
        clearKeyboardBuffer();
    }

    return input;
}

// take a valid input of crud and days and display how much crud theew will be after n days
void fibonacciSequence(int crud, int days)
{
    int fiboStart = 0, fiboNext = crud, fiboRes, counter = 0;

    if (days == 0)
    {
        printf("There will be %d LBS of Crud after %d Days\n", crud, days);
    }
    else if (days < 5)
    {
        printf("There will be %d LBS of Crud after %d Days\n", crud, days);
    }
    else
    {
        for (int i = 0; i < days; i++)
        {
            if (i % 5 == 0)
            {
                fiboRes = fiboStart + fiboNext;
                fiboStart = fiboNext;
                fiboNext = fiboRes;
            }
        }
        printf("There will be %d LBS of Crud after %d Days\n", fiboRes, days);
    }
}

void clearKeyboardBuffer(void)
{
    char c = 'a';
    while (c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}

int userWishesToContinue(void)
{
    char c;
    printf("Do you wish to continue (y/n): ");
    scanf("%c", &c);
    clearKeyboardBuffer();

    while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
    {
        printf("Invalid Input-- Do you wish to continue (y/n): ");
        scanf("%c", &c);
        clearKeyboardBuffer();
    }

    return (c == 'y' || c == 'Y');
}