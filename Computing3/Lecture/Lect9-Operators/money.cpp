#include "money.hpp"

void Money::set_cents(int new_cents)
{
    cents = new_cents;
}

void Money::set_dollars(int new_dollars)
{
    dollars = new_dollars;
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
const Money operator+(const Money& a, const Money& b)
{   
    int total_cents = a.to_cents() + b.to_cents();
    return Money(total_cents);
}
const Money Money::operator+(const Money& operand)
{
    int total_cents = to_cents() + operand.to_cents();
    return Money(total_cents);
}

ostream& operator<<(ostream &out, const Money &right_operand)
{
    out << "$";
    out << right_operand.get_dollars();
    out << ".";
    if(right_operand.get_cents() < 10) out << "0";
    out << right_operand.get_cents();
    return out;
}

istream& operator>>(istream &in, Money &right_operand)
{
    char dollar_sign;
    double dollar_ammount;

    in >> dollar_sign;
    if (dollar_sign != '$')
    {
        cout << "The format should be $x.yy";
        exit(1);
    }
    in >> dollar_ammount;
    int total_cents = static_cast<int>(round(dollar_ammount * 100));
    right_operand.set_dollars(total_cents / 100);
    right_operand.set_cents(total_cents % 100);

    return in;
}

// overloading ++ prefix, incremented first then new value is used
Money &operator++(Money& operand)
{
    // int dollars = operand.get_dollars();
    // int cents = operand.get_cents();

    // operand.set_dollars(dollars + 1);
    // operand.set_cents(cents + 1);
    
    operand.dollars ++;
    operand.cents ++;

    return operand;
}

// overloading ++ postfix, old value used then incriment
const Money operator++(Money operand, int)
{
    int dollars = operand.dollars;
    int cents = operand.cents;

    operand.set_dollars(dollars + 1);
    operand.set_cents(cents + 1);

    return Money(dollars, cents);
}
