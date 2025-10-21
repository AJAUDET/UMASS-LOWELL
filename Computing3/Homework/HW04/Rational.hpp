#include <iostream>
using namespace std;

class Rational
{
 private:
  int numerator;
  int denominator;
  void rationalize();
  int gcd(int a, int b);
 public:
  Rational();
  Rational(int new_numerator, int new_denominator);
  Rational(int whole_number);

  int getNum(void) const;
  int getDenom(void) const;

  friend const bool operator==(const Rational& left, const Rational& right);
  friend const bool operator!=(const Rational& left, const Rational& right);
  friend const bool operator<(const Rational& left, const Rational& right);
  friend const bool operator<=(const Rational& left, const Rational& right);
  friend const bool operator>(const Rational& left, const Rational& right);
  friend const bool operator>=(const Rational& left, const Rational& right);
  friend const Rational operator+(const Rational &left, const Rational &right);
  friend const Rational operator-(const Rational &left, const Rational &right);
  friend const Rational operator*(const Rational &left, const Rational &right);
  friend const Rational operator/(const Rational &left, const Rational& right);
};

const bool operator==(const Rational& left, const Rational& right);
const bool operator!=(const Rational& left, const Rational& right);
const bool operator<(const Rational& left, const Rational& right);
const bool operator<=(const Rational& left, const Rational& right);
const bool operator>(const Rational& left, const Rational& right);
const bool operator>=(const Rational& left, const Rational& right);
const Rational operator+(const Rational &left, const Rational &right);
const Rational operator-(const Rational &left, const Rational &right);
const Rational operator*(const Rational &left, const Rational &right);
const Rational operator/(const Rational &left, const Rational& right);
ostream &operator<<(ostream &out, const Rational &right);
istream &operator>>(istream &in, Rational &right);
