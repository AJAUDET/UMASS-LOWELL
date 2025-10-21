#ifndef TEMP_H
#define TEMP_H

#include <iostream>
using namespace std;

template <class T>
class Pair {
 public:
    // cosntructors
   Pair();
   Pair(T new_first, T new_second);

    // getters and setters
   template <class T>
   T get_first(void) const;
   template <class T>
   T get_second(void) const;

   template <class T>
   void set_first(T new_first);

   template <class T>
   void set_second(T new_second);

 private:
   T first;
   T second;
};

template <typename T>
ostream& operator<<(ostream& out, const Pair<T>& pair);

#endif
