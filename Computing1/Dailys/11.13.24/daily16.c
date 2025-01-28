/*
    Program: daily16.c
    Author: AJ Audet
    Date: November 11 2024
    Time spent: 45 min
    Sources of Help: Instruction Sheet, there are 2.2046 pounds in a kilogram, 1000 grams
    in a kilogram, and 16 ounces in a pound. there are 0.3048 meters in a foot, 12 inches in a foot, and
    100 centimeters in a meter.
    Purpose: The purpose of this program is to take in a weight/length and convert it to either metric or imperial and display
          The converted weight/length
*/

#include <stdio.h>

typedef enum
{
    us_to_metric = 1,
    metric_to_us
} CONVERT;

int getBaseUnitLengh(CONVERT type);
int getBaseUnitWeight(CONVERT type);
double getSubUnitLength(CONVERT type);
double getSubUnitWeight(CONVERT type);
CONVERT getConversionType();
int getProcess(void);
void convertLength(int unit, double unit2, CONVERT type);
void convertWeight(int unit, double unit2, CONVERT type);
void clearKeyboardBuffer(void);

int main(void)
{
    CONVERT conversionType;
    int process;
    int baseUnit;
    double subUnit;

    process = getProcess();

    while (process != 0)
    {

        if (process == 0)
            break;
        conversionType = getConversionType();

        switch (process)
        {
        case 1:
            baseUnit = getBaseUnitLengh(conversionType);
            subUnit = getSubUnitLength(conversionType);

            convertLength(baseUnit, subUnit, conversionType);
            break;

        case 2:
            baseUnit = getBaseUnitWeight(conversionType);
            subUnit = getSubUnitWeight(conversionType);
            convertWeight(baseUnit, subUnit, conversionType);
            break;
        }

        process = getProcess();
    }

    return 0;
}

// take a valid integer input and return valid enum
CONVERT getConversionType()
{
    int noc, input;
    printf("1.US to Metric, 2. Metric to US: ");
    noc = scanf("%d", &input);
    clearKeyboardBuffer();

    while ((input > 2 || input < 1) || noc != 1)
    {
        printf("1.US to Metric, 2. Metric to US: ");
        noc = scanf("%d", &input);
        clearKeyboardBuffer();
    }
    return input;
}

// take a valid input and return the process type
int getProcess(void)
{
    int choice, noc;
    printf("Do you want to convert 1. Length or 2. Weight, enter 0 to EXIT: ");
    noc = scanf("%d", &choice);
    clearKeyboardBuffer();
    while ((choice > 2 || choice < 0) || noc != 1)
    {
        printf("ERROR--Do you want to convert 1. Length or 2. Weight, enter 0 to EXIT: ");
        noc = scanf("%d", &choice);
        clearKeyboardBuffer();
    }

    return choice;
}

// take a valid intiger input and return that value
int getBaseUnitLengh(CONVERT type)
{
    int noc, input;

    switch (type)
    {
    case us_to_metric:
        printf("Please enter a length in FEET: ");
        noc = scanf("%d", &input);

        while (noc != 1)
        {
            printf("ERROR -- Please enter a valid length in FEET: ");
            noc = scanf("%d", &input);
        }
        return input;
        break;

    case metric_to_us:
        printf("Please enter a length in METERS: ");
        noc = scanf("%d", &input);

        while (noc != 1)
        {
            printf("ERROR -- Please enter a valid length in METERS: ");
            noc = scanf("%d", &input);
        }
        return input;
        break;
    }
}

// take a valid intiger input and return that value
int getBaseUnitWeight(CONVERT type)
{
    int noc, input;

    switch (type)
    {
    case us_to_metric:
        printf("Please enter a weigth in POUNDS: ");
        noc = scanf("%d", &input);

        while (noc != 1)
        {
            printf("ERROR -- Please enter a valid weight in POUNDS: ");
            noc = scanf("%d", &input);
        }
        return input;
        break;

    case metric_to_us:
        printf("Please enter a weight in KILOGRAMS: ");
        noc = scanf("%d", &input);

        while (noc != 1)
        {
            printf("ERROR -- Please enter a valid weigth in KILOGRAMS: ");
            noc = scanf("%d", &input);
        }
        return input;
        break;
    }
}

// take a valid double input and return that value
double getSubUnitLength(CONVERT type)
{
    int noc;
    double input;

    switch (type)
    {
    case us_to_metric:
        printf("Please enter a length in INCHES: ");
        noc = scanf("%lf", &input);

        while (noc != 1)
        {
            printf("ERROR -- Please enter a valid length in INCHES: ");
            noc = scanf("%lf", &input);
        }
        return input;
        break;

    case metric_to_us:
        printf("Please enter a length in CENTIMETERS: ");
        noc = scanf("%lf", &input);

        while (noc != 1)
        {
            printf("ERROR -- Please enter a valid length in CENTIMETERS: ");
            noc = scanf("%lf", &input);
        }
        return input;
        break;
    }
}

// take a double intiger input and return that value
double getSubUnitWeight(CONVERT type)
{
    int noc;
    double input;

    switch (type)
    {
    case us_to_metric:
        printf("Please enter a weight in OUNCES: ");
        noc = scanf("%lf", &input);

        while (noc != 1)
        {
            printf("ERROR -- Please enter a valid weight in OUNCES: ");
            noc = scanf("%lf", &input);
        }
        return input;
        break;

    case metric_to_us:
        printf("Please enter a weight in GRAMS: ");
        noc = scanf("%lf", &input);

        while (noc != 1)
        {
            printf("ERROR -- Please enter a valid weight in GRAMS: ");
            noc = scanf("%lf", &input);
        }
        return input;
        break;
    }
}

// take two valid inputs for length and convert to its counterpart
// convert the base unit to the subunit then convert to the counterpart
void convertLength(int unit, double unit2, CONVERT type)
{
    int feet, meters;
    double inches, centimeters;
    switch (type)
    {
    case us_to_metric:
        // convert to inches then sonvert in to cm
        // then convert cm to m + cm
        inches = (unit * 12) + unit2;

        centimeters = inches * 2.54;
        meters = centimeters / 100;

        centimeters -= (meters * 100.0);

        printf("%d ft %.2lf in converted %d m %.2lf cm\n", unit, unit2, meters, centimeters);

        break;

    case metric_to_us:
        centimeters = (unit * 100) + unit2;

        inches = (centimeters / 2.54);
        feet = (inches / 12);

        inches -= (feet * 12.0);

        printf("%d m %.2lf cm converted %d ft %.2lf in\n", unit, unit2, feet, inches);

        break;
    }
}

// take two valid inputs for weight and convert to its counterpart
// convert the subunit to the base unit then convert to the counterpart
void convertWeight(int unit, double unit2, CONVERT type)
{
    int pounds, kilograms;
    double ounces, grams;

    switch (type)
    {
    case us_to_metric:
        ounces = (unit * 16) + unit2;
        grams = (ounces * 28.34);

        kilograms = (grams / 1000);
        grams -= (kilograms * 1000);

        printf("%d lbs %.2lf oz converted is %d kg %.2lf g\n", unit, unit2, kilograms, grams);
        break;

    case metric_to_us:
        grams = (unit * 1000) + unit2;
        ounces = (grams / 28.34);

        pounds = (ounces / 16);
        ounces -= (pounds * 16);

        printf("%d kg %.2lf g converted is %d lbs %.2lf oz\n", unit, unit2, pounds, ounces);
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