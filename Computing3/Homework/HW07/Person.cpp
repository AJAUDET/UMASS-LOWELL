#include "Person.hpp"

Person::Person()
{
    name = "none";
}

Person::Person(string new_name)
{
    name = new_name;
}

Person::Person(const Person &obj)
{
    name = obj.name;
}

string Person::getName() const
{
    return name;
}

Person &Person::operator=(const Person &rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
    }
    return *this;
}

istream &operator>>(istream &is, Person &obj)
{
    is >> obj.name;
    return is;
}

ostream &operator<<(ostream &os, const Person &obj)
{
    os << obj.getName();
    return os;
}
