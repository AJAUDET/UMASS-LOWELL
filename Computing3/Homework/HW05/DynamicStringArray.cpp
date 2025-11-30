#include "DynamicStringArray.hpp"

// default constructor
DynamicStringArray::DynamicStringArray() {
    dynamicArray = nullptr;
    size = 0;
}

// copy constructor
DynamicStringArray::DynamicStringArray(const DynamicStringArray& other) {
    size = other.size;

    if (size == 0) {
        dynamicArray = nullptr;
    } else {
        dynamicArray = new string[size];
        for (int i = 0; i < size; i++) {
            dynamicArray[i] = other.dynamicArray[i];
        }
    }
}

// copy assignment operator
DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& other) {
    // check for self-assignment
    if (this == &other) {
        return *this;
    }

    delete[] dynamicArray;

    // copy size
    size = other.size;

    // copy elements
    if (size == 0) {
        dynamicArray = nullptr;
    } else {
        dynamicArray = new string[size];
        for (int i = 0; i < size; i++) {
            dynamicArray[i] = other.dynamicArray[i];
        }
    }

    return *this;
}

// deconstructor
DynamicStringArray::~DynamicStringArray() {
    delete[] dynamicArray;
}

// post cond: returns the current size of the array
int DynamicStringArray::getSize() const {
    return size;
}

// pre cond: valid string entry is given
// post cond: entry is added to the end of the array
void DynamicStringArray::addEntry(const string& entry) {
    // create new array one element larger
    string* newArray = new string[size + 1];

    // copy all elements from old array
    for (int i = 0; i < size; i++) {
        newArray[i] = dynamicArray[i];
    }

    // add new string to the end
    newArray[size] = entry;

    // delete old array
    delete[] dynamicArray;

    // update pointer and size
    dynamicArray = newArray;
    size++;
}

// pre cond: the given entry exists in the array
// post cond: the specified entry is deleted from the array
bool DynamicStringArray::deleteEntry(const string& entry) {
    // search for the string
    int foundIndex = -1;
    for (int i = 0; i < size; i++) {
        if (dynamicArray[i] == entry) {
            foundIndex = i;
            break;
        }
    }

    // if not found, return false
    if (foundIndex == -1) {
        return false;
    }

    // handle case where array becomes empty
    if (size == 1) {
        delete[] dynamicArray;
        dynamicArray = nullptr;
        size = 0;
        return true;
    }

    string* newArray = new string[size - 1];

    // copy all elements to new array
    int newIndex = 0;
    for (int i = 0; i < size; i++) {
        if (i != foundIndex) {
            newArray[newIndex] = dynamicArray[i];
            newIndex++;
        }
    }

    // delete old array
    delete[] dynamicArray;

    // update pointer and size
    dynamicArray = newArray;
    size--;

    return true;
}

// pre cond: index is in bounds of the array
// post cond: return a pointer at the specified index
string* DynamicStringArray::getEntry(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    return &dynamicArray[index];
}
