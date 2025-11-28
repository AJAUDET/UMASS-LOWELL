/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University's Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
 
Date: 9/4/25
Name: AJ Audet
*/
/*
    We making the dice game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_dice(int number_of_dice, int dice_results[]);
void clear_keyboard_buffer(void);

int main(void)
{
    int number_of_dice = 0;
    int sum_of_dice = 0;
    double average;

    printf("Please enter how many dice you want to roll (2-5): ");
    scanf("%d",&number_of_dice);
    clear_keyboard_buffer();
    while(number_of_dice < 2 || number_of_dice > 5)
    {
        printf("Please enter a valid number of dice (2-5): ");
        scanf("%d", &number_of_dice);
        clear_keyboard_buffer();
    }

    int dice_results[number_of_dice];
    roll_dice(number_of_dice, dice_results);

    for(int i = 0; i < number_of_dice; i++)
    {
        printf("Dice %d, Result: %d\n", i + 1, dice_results[i]);
        sum_of_dice += dice_results[i];
    }
    printf("Sum of all dice: %d\n", sum_of_dice);
    average = (double) sum_of_dice / number_of_dice;
    printf("Average of all dice: %.2lf\n", average);

    return 0;
}


// preconditiions: recieves a valid number of dice, and an initialized array to store the results of each dice
// postcondition: all of the values from the 6 sided dice are stored in the array
void roll_dice(int number_of_dice, int dice_results[])
{
    srand(time(NULL));
    int i;
    for(i = 0; i < number_of_dice; i++)
    {
        dice_results[i] = (rand() % 6) + 1;
    }
}

void clear_keyboard_buffer(void)
{
    char c = 'a';
    while(c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}
