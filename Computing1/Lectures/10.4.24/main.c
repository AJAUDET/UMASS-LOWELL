#include <stdio.h>

void clearKeyboardBuffer(void);

int gradeEval(char grade);

int betterGradeEval(char grade);

int bestGradeEval(char grade);

int main(int argc, char *argv[])
{
    char grade = 'A';

    while (1)
    {
        printf("Please enter your Letter Grade (use X to exit): ");
        scanf("%c", &grade);
        clearKeyboardBuffer();
        if (!bestGradeEval(grade))
        {
            return 0;
        }
    }

    return 0;
}

// genrally messy, least optimized
int gradeEval(char grade)
{
    if (grade == 'A')
    {
        printf("CONGRATS!\n");
    }
    else
    {
        if (grade == 'B')
        {
            printf("Well done\n");
        }
        else
        {
            if (grade == 'C')
            {
                printf("With a bit more effort you can get that B you want\n");
            }
            else
            {
                if (grade == 'D')
                {
                    printf("Don't give up, go to office hours or tutoring for more help\n");
                }
                else
                {
                    if (grade == 'F')
                    {
                        printf("Sorry better luck next time\n");
                    }
                    else
                    {
                        if (grade == 'x' || grade == 'X')
                        {
                            printf("Thank you for using the grade checker\n");
                            return 0;
                        }
                        else
                        {
                            printf("Invalid grade\n");
                        }
                    }
                }
            }
        }
    }
    return 1;
}

// introduction of else if statements to condense code, more efficient
int betterGradeEval(char grade)
{
    if (grade == 'A')
    {
        printf("CONGRATS!\n");
    }
    else if (grade == 'B')
    {
        printf("Well done\n");
    }
    else if (grade == 'C')
    {
        printf("With a bit more effort you can get that B you want\n");
    }
    else if (grade == 'D')
    {
        printf("Don't give up, go to office hours or tutoring for more help\n");
    }
    else if (grade == 'F')
    {
        printf("Sorry better luck next time\n");
    }
    else if (grade == 'x' || grade == 'X')
    {
        printf("Thank you for using the grade checker\n");
        return 0;
    }
    else
    {
        printf("Invalid grade\n");
    }
    return 1;
}

// usage of switch statements to further optimize the function
    // switch statement are really easy to control the flow of the algorithm
    // less complicated than multiple if/else if statements
int bestGradeEval(char grade)
{
    switch (grade)
    {
    case 'A':
        printf("CONGRATS!\n");
        break;
    case 'B':
        printf("Well done\n");
        break;
    case 'C':
        printf("With a bit more effort you can get that B you want\n");
        break;
    case 'D':
        printf("Don't give up, go to office hours or tutoring for more help\n");
        break;
    case 'F':
        printf("Sorry better luck next time\n");
        break;
    case 'x':
        printf("Thank you for using the grade checker\n");
        return 0;
        break;
    case 'X':
        printf("Thank you for using the grade checker\n");
        return 0;
        break;
    default:
        printf("Invalid grade\n");
    }
    return 1;
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