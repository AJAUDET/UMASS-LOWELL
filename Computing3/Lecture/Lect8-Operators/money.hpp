#include <iostream>
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
    void set_cents(int new_cents);
    void set_dollars(int new_dollars);

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

// overloading extraction operator
// cin >> m1; => <<(cin, m4);
istream& operator >>(istream &in, Money &right_operand);
