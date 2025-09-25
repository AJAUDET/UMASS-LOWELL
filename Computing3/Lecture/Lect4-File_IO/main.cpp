#include <iostream> // cout and cin
#include <fstream>
#include <cstdlib> // srand() and rand()
#include <ctime>   // time()
using namespace std;

/*
const int MIN_NUM_DICE = 2;
const int MAX_NUM_DICE = 5;
const int MAX_DICE_VALUE = 6;
*/

void getInt(int &num);
double calc_ave(const int arr[], int size);
int calc_sum(const int arr[], int size);

int main(void)
{
    srand((unsigned int)time(NULL));

    int num_dice;
    string in_file_path = "data.txt";
    string out_file_path = "output.txt";
    ifstream inFile;
    ofstream outFile;
    inFile.open(in_file_path);
    outFile.open(out_file_path);

    if (inFile.fail())
    {
        cout << "Cant open file" << endl;
        exit(1);
    }

    if (outFile.fail())
    {
        cout << "Cant open file" << endl;
        exit(1);
    }

    if (inFile >> num_dice)
    {
        cout << "There are " << num_dice << " dice" << endl;
    }
    else
    {
        cerr << "Can't read number" << endl;
        exit(1);
    }

    /*
    do
    {
        cout << "Enter how many dice you want to roll (2~5): ";
        getInt(num_dice);
    } while (num_dice < MIN_NUM_DICE || num_dice > MAX_NUM_DICE);
    */

    // int dice[MAX_NUM_DICE];
    int *dice;
    // dice = (int*) malloc(sizeof(int) * num_dice); // usual way to do allocation

    dice = new int[num_dice];
    if (dice == nullptr)
    {
        cerr << "Error allocating memory" << endl;
        exit(1);
    }

    int i = 0;
    while (inFile >> dice[i])
    {
        cout << "Dice value: " << dice[i] << endl;
        i++;
    }
    int sum = calc_sum(dice, num_dice);

    cout << "Sum of " << num_dice << " dice: " << sum << endl;

    double avg = calc_ave(dice, num_dice);
    cout << "Average of all dice is: " << avg << endl;

    // free(dice);
    delete[] dice; // return the memory of the array dice
    dice = nullptr;

    inFile.close();
    outFile.close();

    return 0;
}

void getInt(int &num)
{
    cin >> num;
}

double calc_ave(const int arr[], int size)
{
    int i;
    int sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int calc_sum(const int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}