#include "Template.hpp"

void swap(int& num1, int& num2);
void swap(double& num1, double& num2);

template <class T1, class T2>                      // class means type or classification, alt use typename
void template_swap(T1 &num1, T2 &num2);



int main(void)
{
    Pair<int> intPair;
    cout << intPair << endl;

    Pair<int> intPair2(32, 45);
    cout << intPair2 << endl;

    Pair<char> charPair('A', 'B');
    cout << charPair << endl;

    return 0;
}


void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void swap(double& num1, double& num2)
{
    double temp = num1;
    num1 = num2;
    num2 = temp;
}

template <class T1, class T2>                      // template prefix
void template_swap(T1 &num1, T2 &num2)
{
    T1 temp = num1;
    num1 = num2;
    num2 = temp;
}


