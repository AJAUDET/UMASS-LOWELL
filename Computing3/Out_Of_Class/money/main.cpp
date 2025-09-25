#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class Money
{
public:
    // constructors
    Money(); // default
    Money(int new_dollars, int new_cents);

    // accessor fucntions
    int get_cents(void);
    int get_dollars(void);

    // mutator funtions
    void set_cents(void);
    void set_dollars(void);

    // conversion (mutator) functions
    void dollars_to_cents(void);

    // display function
    void display(void);

private:
    int dollars;
    int cents;
};

int main(void)
{
    Money my_money;

    my_money.set_cents();
    my_money.set_dollars();
    my_money.display();

    Money your_money(10, 32);
    cout << "\nBefore conversion\n";
    your_money.display();
    your_money.dollars_to_cents();
    cout << "\nAfter conversion\n";
    your_money.display();


    return 0;
}

Money::Money()
{
    dollars = 0;
    cents = 0;
}

Money::Money(int new_dollars, int new_cents)
{
    dollars = new_dollars;
    cents = new_cents;
}

int Money::get_cents(void)
{
    return cents;
}

int Money::get_dollars(void)
{
    return dollars;
}

void Money::set_cents(void)
{
    while ((cout << "Please enter the ammount of cents you have: ") && (!(cin >> cents) || (cents >= 100) || (cents < 0)))
    {
        cout << "That's not a number less than 100, and greater than or equal to 0! Please try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                // following the example from isocpp
    }
}

void Money::set_dollars(void)
{
    while ((cout << "Please enter the ammount of dollars you have: ") && (!(cin >> dollars) || (dollars < 0)))
    {
        cout << "That's not a number greater than or equal to 0! Please try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                // following the example from isocpp
    }
}

void Money::dollars_to_cents(void)
{
    cents += dollars * 100;
    dollars = 0;
}

void Money::display(void)
{
    cout << "Dollars: " << dollars << "\t";
    cout << "Cents: " << cents << endl;
}