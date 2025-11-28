#include <iostream> // cout and cin
#include <cstdlib> // srand() and rand()
#include <ctime> // time()
using std::cout;
using std::cin;
using std::endl;

const int MIN_NUM_DICE = 2;
const int MAX_NUM_DICE = 5;
const int MAX_DICE_VALUE = 6;

void getInt(int& num);

int main(void)
{
    srand((unsigned int)time(NULL));

    int num_dice, i;
    do
    {
        cout << "Enter how many dice you want to roll (2~5): ";
        getInt(num_dice);
    } while (num_dice < MIN_NUM_DICE || num_dice > MAX_NUM_DICE);
    
    int dice[MAX_NUM_DICE];
    int sum = 0;

    for (i = 0; i < num_dice; i++)
    {
        dice[i] = rand() % MAX_DICE_VALUE + 1;
        cout << "Dice value: " << dice[i] << endl;
        sum += dice[i];
    }
    
    cout << "Sum of " << num_dice << " dice: " << sum << endl;

    double avg = static_cast<double>(sum) / num_dice;
    cout << "Average of all dice is: " << avg << endl;

    return 0;
}

void getInt(int& num)
{
    cin >> num;
}
