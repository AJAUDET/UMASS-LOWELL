/*
    Author: AJ Audet
    Date: October 27 2024
    Purpose: Converts Lengths and Weights // 1 in == 2.54 cm // 2.205 lbs == 1 kg, 1 lbs == .454
    Sources of Help: Google for conversion of In to Cm and Lbs to Kg and vice verca
    Time Spent: 25 mins
*/

#include <stdio.h>

typedef enum
{
    pounds_to_kilos = 1,
    kilos_to_pounds,
    inches_to_centi,
    centi_to_inches
} CHOICE;

int getInput(void);
void clearKeyboardBuffer(void);
CHOICE getConversionType(void);
double getLength(CHOICE type);
double getWeight(CHOICE type);
double convert(double input, CHOICE type);

int main(void)
{
    CHOICE conversionType;
    double length, weight;
    int input;

    // take user input for operation
    do
    {
        input = getInput();
        switch (input)
        {
        case 1:
            conversionType = getConversionType();
            length = getLength(conversionType);
            printf("%g converted is %g\n", length, convert(length, conversionType));
            break;

        case 2:
            conversionType = getConversionType();
            weight = getWeight(conversionType);
            printf("%g converted is %g\n", weight, convert(weight, conversionType));
            break;
        }
    } while (input != 0 );

    return 0;
}

int getInput(void)
{
    int choice, noc;
    printf("Do you want to convert 1. Length or 2. Weight, enter 0 to EXIT: ");
    noc = scanf("%d", &choice);
    clearKeyboardBuffer();
    while ((choice > 2 && choice < 1))
    {
        printf("ERROR--Do you want to convert 1. Length or 2. Weight: ");
        noc = scanf("%d", &choice);
        clearKeyboardBuffer();
    }

    return choice;
}

double getLength(CHOICE type)
{
    int noc;
    double length;

    switch (type)
    {
    case inches_to_centi:
        printf("Enter a length in INCHES: ");
        noc = scanf("%lf", &length);
        clearKeyboardBuffer();
        while (noc != 1)
        {
            printf("Enter a length in INCHES: ");
            noc = scanf("%lf", &length);
            clearKeyboardBuffer();
        }

        return length;

        break;
    case centi_to_inches:
        printf("Enter a length in CENTIMETERS: ");
        noc = scanf("%lf", &length);
        clearKeyboardBuffer();
        while (noc != 1)
        {
            printf("Enter a length in CENTIMETERS: ");
            noc = scanf("%lf", &length);
            clearKeyboardBuffer();
        }

        return length;

        break;
    }
}

double getWeight(CHOICE type)
{
    int noc;
    double length;

    switch (type)
    {
    case pounds_to_kilos:
        printf("Enter a weight in POUNDS: ");
        noc = scanf("%lf", &length);
        clearKeyboardBuffer();
        while (noc != 1)
        {
            printf("Enter a weight in POUNDS: ");
            noc = scanf("%lf", &length);
            clearKeyboardBuffer();
        }

        return length;

        break;
    case kilos_to_pounds:
        printf("Enter a weight in KILOGRAMS: ");
        noc = scanf("%lf", &length);
        clearKeyboardBuffer();
        while (noc != 1)
        {
            printf("Enter a weight in KILOGRAMS: ");
            noc = scanf("%lf", &length);
            clearKeyboardBuffer();
        }

        return length;

        break;
    }
}

CHOICE getConversionType(void)
{
    int noc, input;
    printf("1. LBS to KG, 2. KG to LBS, 3. IN to CM, 4. CM to IN: ");
    noc = scanf("%d", &input);
    clearKeyboardBuffer();

    while (noc != 1)
    {
        printf("1. LBS to KG, 2. KG to LBS, 3. IN to CM, 4. CM to IN: ");
        noc = scanf("%d", &input);
        clearKeyboardBuffer();
    }
    return input;
}

// 1 in == 2.54 cm
// 2.205 lbs == 1 kg
double convert(double input, CHOICE type)
{
    switch (type)
    {
    case pounds_to_kilos:
        return input / 2.205;

    case kilos_to_pounds:
        return input * 2.205;

    case inches_to_centi:
        return input * 2.54;

    case centi_to_inches:
        return input / 2.54;
    default:
        break;
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