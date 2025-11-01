#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person {
 public:
    Person();
    Person(string name);
    Person(const Person& obj);

    string getName() const;
    Person& operator=(const Person& rhs);

    friend istream& operator >>(istream& is, Person& obj);
    friend ostream& operator <<(ostream& os, const Person& obj);
 private:
    string name;
};

istream& operator >>(istream& is, Person& obj);
ostream& operator <<(ostream& os, const Person& obj);
