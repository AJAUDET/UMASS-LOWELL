#include "PFArrayD.hpp"

PFArrayD::PFArrayD(): capacity(50), used(0) {
    a = new double[capacity];
}

PFArrayD::PFArrayD(int capacity) : capacity(capacity), used(0) {
    a = new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD& obj): capacity(obj.capacity), used(obj.used)
{
    a = new double[capacity];
    for (int i = 0; i < used; i++) {
        a[i] = obj.a[i];
    }
}

PFArrayD::~PFArrayD() {
    delete[] a;
}

void PFArrayD::addElement(double element) {
    if (isFull()) {
        throw OutOfRange(used, "Insertion exceeds PFArrayD capacity");
    }
    a[used++] = element;
}

double& PFArrayD::operator[](int index) {
    if (index < 0 || index >= used) {
        throw OutOfRange(index, "Index out of range in PFArrayD");
    }
    return a[index];
}

PFArrayD& PFArrayD::operator=(const PFArrayD& rightSide) {
    if (this == &rightSide)
        return *this;

    // Release old memory
    delete[] a;

    // Copy metadata
    capacity = rightSide.capacity;
    used = rightSide.used;

    // Allocate new memory + copy elements
    a = new double[capacity];
    for (int i = 0; i < used; i++) {
        a[i] = rightSide.a[i];
    }

    return *this;
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
