#include <iostream>
using namespace std;

void mySwap(int& a, int& b);
void mySwap(double& a, double& b);

double addDouble(double a, double b, double c);
double addDouble(double a, double b);

int main(int argc, char *argv[])
{
    int num1 = 35, num2 = -53;
    cout << "BEFORE SWAP: num1: " << num1 << " num2: " << num2 << endl;
    mySwap(num1, num2);
    cout << "AFTER SWAP: num1: " << num1 << " num2: " << num2 << endl;

    double d1 = 35.5, d2 = -53.3;
    cout << "BEFORE SWAP: d1: " << d1 << " d2: " << d2 << endl;
    mySwap(d1, d2);
    cout << "AFTER SWAP: d1: " << d1 << " d2: " << d2 << endl;

    return 0;
}

void mySwap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void mySwap(double& a, double& b)
{
    double temp = a;
    a = b;
    b = temp;
}

double addDouble(double a, double b, double c)
{
    return a + b + c;
}
double addDouble(double& a, double b)
{
    return a + b;
}
