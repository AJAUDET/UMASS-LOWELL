#include <vector>
#include <iostream>
using namespace std;

// Complex number format: a + bi 
class ComplexNumber
{
 public:
    // Constructors
    // Default constructor sets a and b terms to 0
    ComplexNumber(): ComplexNumber(0, 0) {}
    // Value constructor sets a and b fields 
    ComplexNumber(double a, double b): re(a), im(b) {}

    // Accessors
    double getReal(void) const { return re; }
    double getImaginary(void) const { return im; }

    // Mutators
    void setReal(double a) { re = a; }
    void setB(double b) { im = b; }
    
    // Misc. functions
    friend ostream& operator<<(ostream& out, const ComplexNumber n);

    // Return a const ComplexNumber and have a const at the end to keep calling object const 
    const ComplexNumber operator+(const ComplexNumber& rightOp) const;
    const ComplexNumber operator-(const ComplexNumber& rightOp) const;
    const ComplexNumber operator*(const ComplexNumber& rightOp) const;
    const ComplexNumber operator/(const ComplexNumber& rightOp) const;
    const ComplexNumber operator!() const;

 private:
    double re;
    double im;
};

int main(void)
{
    int i;
    vector <ComplexNumber> vect;
    ComplexNumber c1;
    ComplexNumber c2(1, 2);
    ComplexNumber c3(3, 4);
    ComplexNumber c4 = c2 * c3;
    ComplexNumber c5 = c2 / c3;

    cout << "Value of c1 (default constructor):" << endl;
    cout << "c1.Re() == " << c1.getReal() << ", c1.Im() == " << c1.getImaginary() << endl;

    cout << "Value of c2 (value constructor):" << endl;
    cout << "c2.Re() == " << c2.getReal() << ", c1.Im() == " << c2.getImaginary() << endl;

    cout << "c2 + c3 (" << c2 << " + " << c3 << ") == " << c2 + c3 << endl;
    cout << "c2 - c3 (" << c2 << " - " << c3 << ") == " << c2 - c3 << endl;
    cout << "c2 * c3 (" << c2 << " * " << c3 << ") == " << c4 << endl;
    cout << "c2 / c3 (" << c2 << " / " << c3 << ") == " << c5 << endl;
    cout << "(c2/c3) + (c2*c3) == " << c5 + c4 << endl;
    
    cout << "Conjugate of c2 (" << c1 << ") == " << !c2 << endl;

    for (i = 0; i < 10; i++)
    {
        ComplexNumber c6(i, 2*i);
        vect.push_back(c6);
    }

    cout << "Vector output using iterative for-loop:" << endl;
    // iterator implementation for vector
    vector<ComplexNumber>::iterator p;
    for (p = vect.begin(); p != vect.end(); p++)
    {
        cout <<  *p << endl;
    }

    cout << "Vector output using indexed for-loop:" << endl;
    // c approach using indexing
    for (i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << endl;
    }

    return 0;
}

ostream& operator<<(ostream& out, const ComplexNumber n)
{
    out << n.re << "+" << n.im << "i";
    return out;
}

const ComplexNumber ComplexNumber::operator+(const ComplexNumber& rightOp) const {
    return ComplexNumber((re + rightOp.re), (im + rightOp.im));
}

const ComplexNumber ComplexNumber::operator-(const ComplexNumber& rightOp) const {
    return ComplexNumber((re - rightOp.re), (im - rightOp.im));
}

const ComplexNumber ComplexNumber::operator*(const ComplexNumber& rightOp) const {
    // (a + bi)(c + di) = ac - bd + (ad + bc)i
    return ComplexNumber((re * rightOp.re - im * rightOp.im), (re * rightOp.im + im * rightOp.re));
}

const ComplexNumber ComplexNumber::operator/(const ComplexNumber& rightOp) const {
    return ComplexNumber((re * rightOp.re + im * rightOp.im)/(rightOp.re * rightOp.re + rightOp.im * rightOp.im), (im * rightOp.re - re * rightOp.im)/(rightOp.re * rightOp.re + rightOp.im * rightOp.im));
}

const ComplexNumber ComplexNumber::operator!() const {
    return ComplexNumber(re, (im * -1));
}
