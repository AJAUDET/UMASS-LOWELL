#pragma once

#include <limits>
#include <string>
#include <iostream>
using std::string;

class OutOfRange {
 private:
  int bad_index;
  string message;

 public:
  OutOfRange(): bad_index(-1), message("default"){}
  OutOfRange(int index, const string& msg): bad_index(index)
  , message(msg) {}

  int index() const { return bad_index; }
  string err() const { return message; }
};
