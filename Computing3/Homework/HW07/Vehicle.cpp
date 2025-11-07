#include "Vehicle.hpp"
#include <iostream>
using namespace std;

// ===== VEHICLE =====

Vehicle::Vehicle()
    : owner(Person("none")), cylinders(0), manufacturer("none") {}

Vehicle::Vehicle(Person new_owner, int new_cylinders, std::string new_manufacturer)
    : owner(new_owner), cylinders(new_cylinders), manufacturer(new_manufacturer) {}

Vehicle::Vehicle(const Vehicle &v_obj)
    : owner(v_obj.owner), cylinders(v_obj.cylinders), manufacturer(v_obj.manufacturer) {}

Person Vehicle::getOwner() const { return owner; }
int Vehicle::getNumCylinders() const { return cylinders; }
std::string Vehicle::getManufacturer() const { return manufacturer; }

Vehicle& Vehicle::operator=(const Vehicle &v_obj) {
    if (this != &v_obj) {
        owner = v_obj.owner;
        cylinders = v_obj.cylinders;
        manufacturer = v_obj.manufacturer;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vehicle& v) {
    out << "Manufacturer: " << v.manufacturer
        << ", Cylinders: " << v.cylinders
        << ", Owner: " << v.owner.getName();
    return out;
}

Vehicle::~Vehicle() {
    cout << "Vehicle destructor called for " << manufacturer << endl;
}

// ===== TRUCK =====

Truck::Truck()
    : Vehicle(), loadCapacity(0.0), towingCapacity(0) {}

Truck::Truck(Vehicle v_obj, double new_loadCap, int new_towCap)
    : Vehicle(v_obj), loadCapacity(new_loadCap), towingCapacity(new_towCap) {}

Truck::Truck(const Truck &t_obj)
    : Vehicle(t_obj), loadCapacity(t_obj.loadCapacity), towingCapacity(t_obj.towingCapacity) {}

double Truck::getLoadCapacity() const { return loadCapacity; }
int Truck::getTowingCapacity() const { return towingCapacity; }

Truck& Truck::operator=(const Truck &t_obj) {
    if (this != &t_obj) {
        Vehicle::operator=(t_obj);
        loadCapacity = t_obj.loadCapacity;
        towingCapacity = t_obj.towingCapacity;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Truck& t) {
    out << static_cast<const Vehicle&>(t)
        << ", Load capacity: " << t.loadCapacity
        << ", Towing capacity: " << t.towingCapacity;
    return out;
}

Truck::~Truck() {
    cout << "Truck destructor called\n";
}
