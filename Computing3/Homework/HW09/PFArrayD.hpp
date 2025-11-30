//
//  PFArrayD.hpp
//  UnitTestingTemplateAgain
//
//  Created by Lin, Sirong on 11/17/25.
//

// Objects of this class are partially filled arrays of doubles.

#pragma once

#include <string>
#include "OutOfRange.hpp"
using std::string;

class PFArrayD {
 public:
  // Initializes with a capacity of 50.
  PFArrayD();
  PFArrayD(int capacity);
  PFArrayD(const PFArrayD& obj);
  ~PFArrayD();

  // Precondition: The array is not full.
  // Postcondition: The element has been added.
  void addElement(double element);

  // Returns true if the array is full, false otherwise.
  bool isFull() const { return (capacity == used); }
  int getCapacity() const { return capacity; }
  int getSize() const { return used; }

  // Empties the array.
  void clearArray(){ used = 0; }

  // Read and change access to elements 0 through numberUsed - 1.
  double& operator[](int index);

  PFArrayD& operator =(const PFArrayD& rightSide);

 private:
  // for an array of doubles.
  double *a;

  // for the size of the array.
  int capacity;

  // for the number of array positions currently in use.
  int used;
};

void testException();
