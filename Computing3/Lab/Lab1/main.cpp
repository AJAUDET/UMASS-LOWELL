#include <iostream> // cin cout 
#include <iomanip> // setprecision()
#include <cmath>

using namespace std;

int main()
{
    double intrest_rate, ammount_needed, loan_duration;

    cout << fixed << setprecision(2);

    while (1)
    {
        cout << "Please enter the annual interest rate as a percentage (15 for 15%) (enter 0 to quit): ";
        cin >> intrest_rate;

        if (intrest_rate == 0)
        {
            break;
        }

        cout << "Please enter the amount you would like to receive: ";
        cin >> ammount_needed;

        cout << "Please enter loan period in months: ";
        cin >> loan_duration;

        double loan_dur_years = loan_duration / 12.0;
        double value = ammount_needed / (1 - (intrest_rate / 100.0) * loan_dur_years);
        double monthly = value / loan_duration;

        cout << "The total amount of your loan (including interest at " << intrest_rate
             << "% anually) is $" << value << "." << endl;
        cout << "Your monthly payment for " << loan_duration << " months will be $"
             << monthly << "." << endl;
    }

    return 0;
}
