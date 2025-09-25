#include <money.hpp>

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
    out << right_operand.get_dollars();
    out << ".";
    if(right_operand.get_cents() < 10) out << "0";
    out << right_operand.get_cents();
    return out;
}

istream& operator >>(istream &in, Money &right_operand)
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
