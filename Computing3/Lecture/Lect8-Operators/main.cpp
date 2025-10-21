#include "money.hpp"

int main(void)
{
    Money m1(2,50);
    Money m2(3,50);

    m1.display();
    m2.display();

    Money m3 = m1 + m2;
    
    // m3.display();
    cout << m3 << "\n" << m2 << "\n" << m1 << endl;

    Money m4;

    cout << "enter a money amount $x.yy" << endl;
    cin >> m4;

    cout << m4 << endl;

    return 0;
}

