/*
    Author: AJ Audet
    Date: November 4, 2024
    Purpose: Conversion of imperial to metric units and vice versa // 1 in == 2.54 cm, 100 cm = 1 m // 2.205 lbs == 1 kg
    Sources of Help: used google for conversion of In to Cm and Lbs to Kg and vice versa, knowing that 100 cm is 1m
    Time Spent: 50 min
*/

#include <stdio.h>

typedef enum
{
    us_to_metric = 1,
    metric_to_us
} SYSTEM;

typedef enum
{
    feet = 1,
    inches,
    meters,
    centimeters,
    pounds,
    ounces,
    kilograms,
    grams
} TYPE;

int getProcess(void);
SYSTEM getSystem(void);
TYPE typeFrom(SYSTEM system, int process);
TYPE typeTo(SYSTEM system, int process);
double getLength(TYPE type);
double getWeight(TYPE type);
double convert(double input, TYPE typeFrom, TYPE typeTo);
void clearKeyboardBuffer(void);
void runProgram(void);

int main(int argc, char *argv[])
{
    runProgram();

    return 0;
}

void runProgram(void)
{
    SYSTEM system;
    TYPE convertTo;
    TYPE convertFrom;
    int process;
    double weight, length;

    do
    {
        // process 1: length :: process 2: weight
        // system 1: us to metric :: system 2: metric to us
        process = getProcess();
        switch (process)
        {
        case 1:
            system = getSystem();
            convertFrom = typeFrom(system, process);
            convertTo = typeTo(system, process);
            length = getLength(convertFrom);
            printf("%lf converted is %lf\n", length, convert(length, convertFrom, convertTo));
            break;

        case 2:
            system = getSystem();
            convertFrom = typeFrom(system, process);
            convertTo = typeTo(system, process);
            weight = getWeight(convertFrom);
            printf("%lf converted is %lf\n", weight, convert(weight, convertFrom, convertTo));
            break;
        }

    } while (process != 0);
}

int getProcess(void)
{
    int choice, noc;
    printf("Do you want to convert 1. Length or 2. Weight, enter 0 to EXIT: ");
    noc = scanf("%d", &choice);
    clearKeyboardBuffer();
    while (noc != 1 || (choice > 2 && choice < 1))
    {
        printf("ERROR--Do you want to convert 1. Length or 2. Weight: ");
        noc = scanf("%d", &choice);
        clearKeyboardBuffer();
    }

    return choice;
}

SYSTEM getSystem(void)
{
    int noc, input;
    printf("1.US to Metric, 2. Metric to US: ");
    noc = scanf("%d", &input);
    clearKeyboardBuffer();

    while ((input > 2 && input < 1) || noc != 1)
    {
        printf("1.US to Metric, 2. Metric to US: ");
        noc = scanf("%d", &input);
        clearKeyboardBuffer();
    }
    return input;
}

// process 1: length :: process 2: weight
// system 1: us to metric :: system 2: metric to us
TYPE typeFrom(SYSTEM system, int process)
{
    int choice;
    int noc;
    switch (system)
    {
    case us_to_metric:
        switch (process)
        {
        case 1:
            printf("What do you want to convert from 1. Feet, 2. Inches: ");
            noc = scanf("%d", &choice);
            clearKeyboardBuffer();
            while (noc != 1)
            {
                printf("ERROR-- Would you like to convert 1. Feet, 2. Inches: ");
                noc = scanf("%d", &choice);
                clearKeyboardBuffer();
            }

            return choice;
            break;

        case 2:
            printf("What do you want to convert from 5. Pounds, 6. Ounces: ");
            noc = scanf("%d", &choice);
            clearKeyboardBuffer();
            while (noc != 1)
            {
                printf("ERROR-- Would you like to convert 5. Pounds, 6. Ounces: ");
                noc = scanf("%d", &choice);
                clearKeyboardBuffer();
            }

            return choice;
            break;
        }
        break;

    case metric_to_us:
        switch (process)
        {
        case 1:
            printf("What do you want to convert from 3. Meters, 4. Centimeters: ");
            noc = scanf("%d", &choice);
            clearKeyboardBuffer();
            while (noc != 1)
            {
                printf("ERROR-- Would you like to convert 3. Meters, 4. Centimeters: ");
                noc = scanf("%d", &choice);
                clearKeyboardBuffer();
            }

            return choice;
            break;

        case 2:
            printf("What do you want to convert from 7. Kilograms, 8. Grams: ");
            noc = scanf("%d", &choice);
            clearKeyboardBuffer();
            while (noc != 1)
            {
                printf("ERROR-- Would you like to convert 7. Kilograms, 8. Grams: ");
                noc = scanf("%d", &choice);
                clearKeyboardBuffer();
            }

            return choice;
            break;
        }
        break;
    }
}

TYPE typeTo(SYSTEM system, int process)
{
    int choice;
    int noc;
    switch (system)
    {
    case us_to_metric:
        switch (process)
        {
        case 1:
            printf("What do you want to convert to 3. Meters, 4. Centimeters: ");
            noc = scanf("%d", &choice);
            clearKeyboardBuffer();
            while (noc != 1)
            {
                printf("ERROR-- Would you like to convert 3. Meters, 4. Centimeters: ");
                noc = scanf("%d", &choice);
                clearKeyboardBuffer();
            }

            return choice;
            break;

        case 2:
            printf("What do you want to convert to 7. Kilograms, 8. Grams: ");
            noc = scanf("%d", &choice);
            clearKeyboardBuffer();
            while (noc != 1)
            {
                printf("Would you like to convert 7. Kilograms, 8. Grams: ");
                noc = scanf("%d", &choice);
                clearKeyboardBuffer();
            }

            return choice;

            break;
        }
        break;

    case metric_to_us:
        switch (process)
        {
        case 1:
            printf("What do you want to convert to 1. Feet, 2. Inches: ");
            noc = scanf("%d", &choice);
            clearKeyboardBuffer();
            while (noc != 1)
            {
                printf("ERROR-- Would you like to convert 1. Feet, 2. Inches: ");
                noc = scanf("%d", &choice);
                clearKeyboardBuffer();
            }

            return choice;
            break;

        case 2:
            printf("What do you want to convert from 5. Pounds, 6. Ounces: ");
            noc = scanf("%d", &choice);
            clearKeyboardBuffer();
            while (noc != 1)
            {
                printf("ERROR-- Would you like to convert 5. Pounds, 6. Ounces: ");
                noc = scanf("%d", &choice);
                clearKeyboardBuffer();
            }

            return choice;
            break;
        }
        break;
    }
}

double getLength(TYPE type)
{
    double length;
    int noc;
    switch (type)
    {
    case feet:
        printf("Enter a length in FEET: ");
        noc = scanf("%lf", &length);
        clearKeyboardBuffer();

        while (noc != 1)
        {
            printf("Enter a length in FEET: ");
            noc = scanf("%lf", &length);
            clearKeyboardBuffer();
        }
        return length;
        break;

    case inches:
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

    case meters:
        printf("Enter a length in METERS: ");
        noc = scanf("%lf", &length);
        clearKeyboardBuffer();

        while (noc != 1)
        {
            printf("Enter a length in METERS: ");
            noc = scanf("%lf", &length);
            clearKeyboardBuffer();
        }
        return length;
        break;
    case centimeters:
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
    default:
        break;
    }
}

double getWeight(TYPE type)
{
    double weight;
    int noc;
    switch (type)
    {
    case pounds:
        printf("Enter a weight in POUNDS: ");
        noc = scanf("%lf", &weight);
        clearKeyboardBuffer();

        while (noc != 1)
        {
            printf("Enter a weight in POUNDS: ");
            noc = scanf("%lf", &weight);
            clearKeyboardBuffer();
        }
        return weight;
        break;

    case ounces:
        printf("Enter a weight in OUNCES: ");
        noc = scanf("%lf", &weight);
        clearKeyboardBuffer();

        while (noc != 1)
        {
            printf("Enter a weight in OUNCES: ");
            noc = scanf("%lf", &weight);
            clearKeyboardBuffer();
        }
        return weight;
        break;

    case kilograms:
        printf("Enter a weight in KILOGRAMS: ");
        noc = scanf("%lf", &weight);
        clearKeyboardBuffer();

        while (noc != 1)
        {
            printf("Enter a weight in KILOGRAMS: ");
            noc = scanf("%lf", &weight);
            clearKeyboardBuffer();
        }
        return weight;
        break;
    case grams:
        printf("Enter a weight in GRAMS: ");
        noc = scanf("%lf", &weight);
        clearKeyboardBuffer();

        while (noc != 1)
        {
            printf("Enter a weight in GRAMS: ");
            noc = scanf("%lf", &weight);
            clearKeyboardBuffer();
        }
        return weight;
        break;
    default:
        break;
    }
}

// input a valid length/weight TYPE to convert from and TYPE to convert to
// output should be a conversion between the input and TYPE from to the TYPE to
// 1 in == 2.54 cm, 100 cm = 1 m // 2.205 lbs == 1 kg, 1lb = 16 oz, 1 kg == 1000 g
// to convert ft to m convert ft to in :: in to cm :: cm to m
// same for the reverse
// lb to g:: 1lb == 453.6g :: 1 0z = 28.34 g :: 1 oz = .02834 kg
double convert(double input, TYPE typeFrom, TYPE typeTo)
{
    switch (typeFrom)
    {
    case feet:
        switch (typeTo)
        {
        case meters:
            return ((input * 12.0) * 2.54) / 100.0;
            break;
        case centimeters:
            return (input * 12.0) * 2.54;
            break;
        default:
            break;
        }
        break;

    case inches:
        switch (typeTo)
        {
        case meters:
            return (input * 2.54) * 100.0;
            break;
        case centimeters:
            return input * 2.54;
            break;
        default:
            break;
        }
        break;
    case meters:
        switch (typeTo)
        {
        case feet:
            return input * 3.28;
            break;
        case inches:
            return (input * 100.0) / 2.54;
            break;
        default:
            break;
        }
    case centimeters:
        switch (typeTo)
        {
        case feet:
            return (input / 2.54) * 12.0;
            break;
        case inches:
            return input / 2.54;
            break;
        default:
            break;
        }
    case pounds:
        switch (typeTo)
        {
        case kilograms:
            return input / 2.205;
            break;
        case grams:
            return input * 453.6;
            break;
        default:
            break;
        }
    case ounces:
        switch (typeTo)
        {
        case kilograms:
            return input * 0.02834;
            break;
        case grams:
            return input * 28.34;
            break;
        default:
            break;
        }
    case kilograms:
        switch (typeTo)
        {
        case pounds:
            return input * 2.205;
            break;
        case ounces:
            return (input * 2.205) / 16.0;
            break;
        default:
            break;
        }
    case grams:
        switch (typeTo)
        {
        case pounds:
            return input / 453.6;
            break;
        case ounces:
            return (input / 453.6) / 16.0;
            break;
        default:
            break;
        }
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