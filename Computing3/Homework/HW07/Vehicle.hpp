#pragma once
#include <string>
#include <iostream>
#include "Person.hpp"

class Vehicle : public Person {
 public:
  Vehicle();
  Vehicle(Person new_owner, int new_cylinders, string new_manufacturer);
  Vehicle(const Vehicle &v_obj);
  ~Vehicle();
  Person getOwner() const;
  int getNumCylinders() const;
  string getManufacturer() const;

  Vehicle& operator=(const Vehicle &v);

  friend istream& operator >>(istream& is, Vehicle& obj);
  friend ostream& operator <<(ostream& os, const Vehicle& obj);

 private:
  Person owner;
  int cylinders;
  string manufacturer;
};

istream& operator >>(istream& is, Vehicle& obj);
ostream& operator <<(ostream& os, const Vehicle& obj);

class Truck : public Vehicle {
 public:
   Truck();
   Truck(Vehicle v, double lc, int tc);
   Truck(const Truck &t_obj);
   ~Truck();

   Truck &operator=(const Truck &t);

   Vehicle getVehicle() const;
   int getTowingCapacity() const;
   double getLoadCapacity() const;

   friend istream &operator>>(istream &is, Truck &t);
   friend ostream &operator<<(ostream &os, const Truck &t);

 private:
  Vehicle vehicle;
  double loadCapacity;
  int towingCapacity;
};

istream &operator>>(istream & is, Truck &t);
ostream &operator<<(ostream &os, const Truck &t);
