#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class Money
{
public:
    // constructors
    Money() : dollars(0), cents(0) {}; // default
    Money(int new_dollars, int new_cents) : dollars(new_dollars), cents(new_cents) {};
    Money(int total_cents) : dollars(total_cents / 100), cents(total_cents % 100) {};

    // accessor fucntions
    int get_cents(void) const {
        return cents;
    } // this function will not change the calling object
    int get_dollars(void) const {
        return dollars;
    }

    // mutator funtions
    void set_cents(void);
    void set_dollars(void);

    // conversion (mutator) functions
    int to_cents(void) const;

    // display function
    void display(void) const;

private:
    int dollars;
    int cents;
};

// overloading addition operator
// m1 + m2 => +(m1,m2)
const Money operator +(const Money& a, const Money& b);

// overloading insertion operator
// cout << endl; => operator<<(cout,endl);
ostream& operator <<(ostream &out, const Money &right_operand);


int main(void)
{
    Money m1(2,50);
    Money m2(3,50);

    m1.display();
    m2.display();

    Money m3 = m1 + m2;
    
   m3.display();

    return 0;
}

void Money::set_cents(void)
{
    while ((cout << "Please enter the ammount of cents you have: ") && (!(cin >> cents) || (cents >= 100) || (cents < 0)))
    {
        cout << "That's not a number less than 100, and greater than or equal to 0! Please try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // following the example from isocpp
    }
}

void Money::set_dollars(void)
{
    while ((cout << "Please enter the ammount of dollars you have: ") && (!(cin >> dollars) || (dollars < 0)))
    {
        cout << "That's not a number greater than or equal to 0! Please try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // following the example from isocpp
    }
}

int Money::to_cents(void) const
{
    return (dollars * 100) + cents;
}

void Money::display(void) const
{
    cout << "$" << to_cents()/100.0 << endl;
}

// overloading addition operator
// m1 + m2 => +(m1,m2)
const Money operator + (const Money& a, const Money& b)
{   
    /*
    int total_cents = a.to_cents() + b.to_cents();
    int sum_dollars = total_cents / 100;
    int sum_cents = total_cents % 100;
    Money sum(sum_dollars, sum_cents);
    return sum;
    */

    int total_cents = a.to_cents() + b.to_cents();
    return Money(total_cents);
}

ostream& operator <<(ostream &out, const Money &right_operand)
{
    out << "$";
    out << right_operand.to_cents() / 100.0;
    return out;
}
