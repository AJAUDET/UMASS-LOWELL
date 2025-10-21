#include "Rational.hpp"
using namespace std;


Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int new_numerator,
int new_denominator) : numerator(new_numerator), denominator(new_denominator)
{
    rationalize();
}

Rational::Rational(int whole_number) : numerator(whole_number), denominator(1) {}

int Rational::gcd(int a, int b)
{
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return (a == 0) ? 1 : a;
}

void Rational::rationalize()
{
    if (denominator == 0) throw;
    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    int div = gcd(numerator, denominator);
    numerator /= div;
    denominator /= div;
}

// accessor, returns the value of the numerator
int Rational::getNum(void) const
{
    return numerator;
}

// accessor, returns the value of the denominator
int Rational::getDenom(void) const
{
    return denominator;
}

// friend operator, boolean return type, check if equal
// precond: valid Rational objects are passed to the operator
// postcond: true / false is returned
const bool operator==(const Rational &left, const Rational &right)
{
    return ((left.numerator == right.numerator) &&
    (left.denominator == right.denominator)) ? true : false;
}

// friend operator, boolean return type, check if not equal
// precond: valid Rational objects are passed to the operator
// postcond: true / false is returned
const bool operator!=(const Rational &left, const Rational &right)
{
    return ((left.numerator == right.numerator) &&
    (left.denominator == right.denominator)) ? false : true;
}

// friend operator, bool return type, check if less than
// for fractions a/b and c/d less than if a * d < b * c
// precond: valid Rational objects are passed to the operator
// postcond: true / false is returned
const bool operator<(const Rational &left, const Rational &right)
{
    return (left.numerator * right.denominator) < (right.numerator * left.denominator);
}

// friend operator, bool return type, check if less than
// for fractions smaller denom == larger number
const bool operator<=(const Rational &left, const Rational &right)
{
    return (left.numerator * right.denominator) <=
    (right.numerator * left.denominator);
}

// same math as less than, just inversed sign
// precond: valid Rational objects are passed to the operator
// postcond: true / false is returned
const bool operator>(const Rational &left, const Rational &right)
{
    return (left.numerator * right.denominator) >
    (right.numerator * left.denominator);
}

// same math as less than or equal to, just inversed sign
// precond: valid Rational objects are passed to the operator
// postcond: true / false is returned
const bool operator>=(const Rational &left, const Rational &right)
{
    return (left.numerator * right.denominator) >=
    (right.numerator * left.denominator);
}

// precondition: two valid rational objects are passed to the function
// postcondition: a new Rational object is created that has the sum of the two objects
const Rational operator+(const Rational &left, const Rational &right)
{
    int new_num = (left.numerator * right.denominator) + (right.numerator * left.denominator);
    int new_denom = (left.denominator * right.denominator);
    return Rational(new_num, new_denom);
}

// precondition: two valid rational objects are passed to the function
// postcondition: a new Rational object is created that has the sum of the two objects
const Rational operator-(const Rational &left, const Rational &right)
{
    int new_num = (left.numerator * right.denominator) - (right.numerator * left.denominator);
    int new_denom = (left.denominator * right.denominator);
    return Rational(new_num, new_denom);
}

// precondition: two valid rational objects are passed to the function
// postcondition: a new Rational object is created that has the product of the two objects
const Rational operator*(const Rational &left, const Rational &right)
{
    int new_num = (left.numerator * right.numerator);
    int new_denom = (left.denominator * right.denominator);
    return Rational(new_num, new_denom);
}

// precondition: two valid rational objects are passed to the function
// postcondition: a new Rational object is created that has the quotient of the two objects
const Rational operator/(const Rational &left, const Rational &right)
{
    if (right.numerator == 0) throw;
    int new_num = (left.numerator * right.denominator);
    int new_denom = (left.denominator * right.numerator);
    return Rational(new_num, new_denom);
}

// precondition: out and right are valid objects
// postcondition: the numerator and denominator are stored in the out object
ostream &operator<<(ostream &out, const Rational &right)
{
    out << right.getNum() << "/" << right.getDenom();
    return out;
}

// precondition: in and right are valid objects
// postcondition: the numerator and denominator are stored in the right argument
// postcondition: the in object stored the numerator and denominator into the right object
istream &operator>>(istream &in, Rational &right)
{
    char div;
    int num, deno;
    in >> num;
    in >> div;
    if (div != '/')
    {
        cout << "The format should be x/y";
        exit(1);
    }
    in >> deno;

    right = Rational(num, deno);
    return in;
}
