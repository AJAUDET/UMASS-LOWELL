#include "PFArrayD.hpp"
using namespace std;

PFArrayD::PFArrayD() : capacity(50), used(0) {
    a = new double[capacity];
}

PFArrayD::PFArrayD(int cap) : capacity(cap), used(0) {
    if (cap <= 0) throw OutOfRange(cap, "capacity must be > 0");
    a = new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD& obj)
    : capacity(obj.capacity), used(obj.used)
{
    a = new double[capacity];
    for (int i = 0; i < used; i++)
        a[i] = obj.a[i];
}

PFArrayD& PFArrayD::operator=(const PFArrayD& rhs) {
    if (this == &rhs) return *this;

    delete[] a;

    capacity = rhs.capacity;
    used = rhs.used;

    a = new double[capacity];
    for (int i = 0; i < used; ++i)
        a[i] = rhs.a[i];

    return *this;
}

PFArrayD::~PFArrayD() {
    delete[] a;
}

void PFArrayD::addElement(double element) {
    if (used >= capacity)
        throw OutOfRange(used, "addElement: array full");

    a[used++] = element;
}

double& PFArrayD::operator[](int index) {
    if (index < 0 || index >= used)
        throw OutOfRange(index, "operator[]: index out of bounds");

    return a[index];
}

void testException() {
    PFArrayD arr(3);

    cout << "Testing normal insertions..." << endl;
    arr.addElement(1.1);
    arr.addElement(2.2);
    arr.addElement(3.3);

    cout << "Attempting insertion into full array..." << endl;
    try {
        arr.addElement(4.4);  // should throw
    }
    catch (OutOfRange& e) {
        cout << "Caught OutOfRange exception:" << endl;
        cout << "  Error: " << e.err() << endl;
        cout << "  Offending index: " << e.index() << endl;
    }

    cout << "Attempting out-of-range read..." << endl;
    try {
        cout << arr[5];  // should throw
    }
    catch (OutOfRange& e) {
        cout << "Caught OutOfRange exception:" << endl;
        cout << "  Error: " << e.err() << endl;
        cout << "  Offending index: " << e.index() << endl;
    }
}
