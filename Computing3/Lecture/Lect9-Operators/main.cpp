#include "money.hpp"

int main(void)
{
    Money m1(2,50);
    Money m2(3,50);

    // m1.display();
    // m2.display();
    cout << m1 << endl;
    cout << m2 << endl;

    Money m3 = m1 + m2;
    
    // m3.display();
    cout << m3 << "\n" << m2 << "\n" << m1 << endl;

    Money m4;

    cout << "enter a money amount $x.yy" << endl;
    cin >> m4;

    cout << m4 << endl;

    Money m5 = ++m4;
    cout << m5 << endl;

    Money m6;
    m6 = m5 + m4;
    cout << m6 << endl;

    return 0;
}

