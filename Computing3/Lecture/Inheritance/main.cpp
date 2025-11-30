#include <iostream>
using namespace std;

class Parent {
 private:
  int n;
 public:
  Parent(): n(0) {};
  Parent(int num): n(num) {};
  int get_N() const {return n;};
  void set_N(int num) {n = num;};
};

class Child:public Parent {
 public:
  void displayN() const {
    cout << "n is: " << get_N() << endl;
  };
  void displayD(void) const {
    cout << "d is: " << d << endl;
  };
 private:
  double d;
};

int main(void)
{
    Parent p(23);
    cout << p.get_N() << endl;
    Child c;
    c.displayD();
    c.displayN();
}