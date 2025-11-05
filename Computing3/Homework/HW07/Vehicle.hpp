#pragma once

#include "Person.hpp"

class Vehicle : public Person {
 public:
  Vehicle();
  Vehicle(Person new_owner, int new_cylinders, string new_manufacturer);
  Vehicle(const Vehicle &v_obj);
  string getOwner();
  int getCylinders();
  string getManufacturer();

  friend istream& operator >>(istream& is, Vehicle& obj);
  friend ostream& operator <<(ostream& os, const Vehicle& obj);

  private:
  Person owner;
  int cylinders;
  string manufacturer;
};

istream& operator >>(istream& is, Vehicle& obj);
ostream& operator <<(ostream& os, const Vehicle& obj);