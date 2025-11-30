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
double calc_ave(const int arr[], int size);

int main(void)
{
    srand((unsigned int)time(NULL));

    int num_dice, i;
    do
    {
        cout << "Enter how many dice you want to roll (2~5): ";
        getInt(num_dice);
    } while (num_dice < MIN_NUM_DICE || num_dice > MAX_NUM_DICE);
    
    // int dice[MAX_NUM_DICE];
    int *dice;
    // dice = (int*) malloc(sizeof(int) * num_dice); // usual way to do allocation

    dice = new int[num_dice];
    if (dice == nullptr)
    {
        std::cerr << "Error allocating memory" << endl;
        exit(1);
    }

    int sum = 0;

    for (i = 0; i < num_dice; i++)
    {
        dice[i] = rand() % MAX_DICE_VALUE + 1;
        cout << "Dice value: " << dice[i] << endl;
        sum += dice[i];
    }
    
    cout << "Sum of " << num_dice << " dice: " << sum << endl;

    double avg = calc_ave(dice, num_dice);
    cout << "Average of all dice is: " << avg << endl;

    // free(dice);
    delete []dice; // return the memory of the array dice
    dice = nullptr;
    return 0;
}

void getInt(int& num)
{
    cin >> num;
}

double calc_ave(const int arr[], int size)
{
    int i;
    int sum = 0;
    for(i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}
