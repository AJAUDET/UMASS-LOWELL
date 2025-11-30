#include "Rational.hpp"

int main(void)
{
    Rational r1(1, 3);
    Rational r2(2, 3);

    Rational r3 = r1 + r2;
    cout << r3;
    
    Rational r4 = r2 - r1;
    cout << r4;
    Rational r5, r6;
    cin >> r5;
    cin >> r6;
    
    cout << r5 + r6;
    cout << r5 - r6;
    cout << r5 * r6;
    cout << r5 / r6;
}