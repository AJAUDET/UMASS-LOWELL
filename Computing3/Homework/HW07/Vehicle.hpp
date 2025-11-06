#pragma once

#include "Person.hpp"

class Vehicle : public Person {
 public:
  Vehicle();
  Vehicle(Person new_owner, int new_cylinders, string new_manufacturer);
  Vehicle(const Vehicle &v_obj);
  ~Vehicle() { cout << "Vehicle deconstructor called " << endl; }
  string getOwner();
  int numCylinders();
  string getManufacturer();

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
  Truck(): vehicle(Vehicle()), loadCapacity(0.0), towingCapacity(0) {};
  Truck(Vehicle v, double lc, int tc): vehicle(v), loadCapacity(lc), towingCapacity(tc) {};
  Truck(const Truck &t_obj);
  ~Truck() { cout << "Vehicle deconstructor called " << endl; };

  Truck &operator=(const Truck &t);

  int getTowingCapacity() const { return towingCapacity; }
  double getLoadCapacity() const { return loadCapacity; }

  friend istream &operator>>(istream & is, Truck &t);
  friend ostream &operator<<(ostream &os, const Truck &t);

private:
  Vehicle vehicle;
  double loadCapacity;
  int towingCapacity;
};

istream &operator>>(istream & is, Truck &t);
ostream &operator<<(ostream &os, const Truck &t);
