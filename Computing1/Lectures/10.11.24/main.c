/*
    EXAM 1 STUDY GUIDE

    1. can you read the code - what does it do
        1a. looking for snakes(smelly food): like integer division, assignment in expressions, semicolons/braces
    2. two's compliments, binary conversions
    3. expression evaluation 
    4. if statements
    5. loops --> for, while, do while -- off by one errors
    6. switch statements
    7. code small problems : physically writing them
    8. functions (return value, definition, body, header)
*/

#include <stdio.h>

enum choice
{
    cel2Far,
    far2Cel
};
typedef enum choice CHOICE;

void clearKeyboardBuffer(void);
int userWishesToContinue(void);
CHOICE getConversionType(void);
double getTemperature(void);
double convertTemperature(double temp, CHOICE userChoice);

// global space
    // global variables cause a lot of problems
    // constants are fine
const double FACTOR = 5.0/9.0;

int main(int argc, char *argv[])
{
    CHOICE conversionType;
    double temperature;
    do
    {
        printf("Temperature Conversion\n");
        conversionType = getConversionType();
        temperature = getTemperature();

        printf("%.1f converted is %.1f\n", temperature, convertTemperature(temperature, conversionType));
    } while (userWishesToContinue());

    return 0;
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

void clearKeyboardBuffer(void)
{
    char c = 'a';
    while (c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}

CHOICE getConversionType(void)
{
    int userInput;
    int noc;
    printf("1 convert Celcius to Fahrenheit\n");
    printf("2 convert Fahrenheit to Celcius\n");
    printf("\nPlease enter 1 or 2: ");
    noc = scanf("%d", &userInput);
    clearKeyboardBuffer();

    while (noc != 1 || (userInput != 1 && userInput != 2))
    {
        printf("\nInvalid input-- Try again");
        printf("\nPlease enter 1 or 2: ");
        noc = scanf("%d", &userInput);
        clearKeyboardBuffer();
    }

    switch (userInput)
    {
    case 1:
        printf("Convert Celcius to Fahrenheit\n");
        return cel2Far;
    case 2:
        printf("Convert Fahrenheit to Celcius\n");
        return far2Cel;
    }
}

double getTemperature(void)
{
    double t;
    int noc;
    printf("Please enter a temperature to convert: ");
    noc = scanf("%lf", &t);
    clearKeyboardBuffer();

    while (noc != 1)
    {
        printf("\nInvalid--\nPlease enter a temperature to convert: ");
        noc = scanf("%lf", &t);
        clearKeyboardBuffer();
    }

    return t;
}

double convertTemperature(double temp, CHOICE userChoice)
{
    double tempConverted;
    switch (userChoice)
    {
    case far2Cel:
        // FACTOR = 8.7: can not modify constants
        tempConverted = (temp - 32.0) * FACTOR;
        return tempConverted;
    
    case cel2Far:
        tempConverted = (temp * 9.0/5.0) + 32.0;
        return tempConverted;
    }
}