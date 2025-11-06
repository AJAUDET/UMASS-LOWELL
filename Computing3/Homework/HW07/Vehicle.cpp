#include <string>
#include "Vehicle.hpp"

Vehicle::Vehicle() {
    owner = Person();
    cylinders = 0;
    manufacturer = "none";
}

Vehicle::Vehicle(Person new_owner, int new_cylinders, string new_manufacturer) {
    owner = new_owner;
    cylinders = new_cylinders;
    manufacturer = new_manufacturer;
}

Vehicle::Vehicle(const Vehicle &v_obj) {
    owner = v_obj.owner;
    cylinders = v_obj.cylinders;
    manufacturer = v_obj.manufacturer;
}

Vehicle& Vehicle::operator=(const Vehicle &v) {
    if (this != &v) {
        owner = v.owner;
        cylinders = v.cylinders;
        manufacturer = v.manufacturer;
    }
    return *this;
}

string Vehicle::getOwner() {
    return owner.getName();
}

int Vehicle::numCylinders() {
    return cylinders;
}

string Vehicle::getManufacturer() {
    return manufacturer;
}

istream& operator >>(istream& is, Vehicle& obj) {
    is >> obj.owner;
    is >> obj.cylinders;
    is >> obj.manufacturer;
    return is;
}

ostream& operator <<(ostream& os, const Vehicle& obj) {
    os << obj.owner << " ";
    os << obj.cylinders << " ";
    os << obj.manufacturer;
    return os;
}

Truck::Truck(const Truck &t_obj) {
    vehicle = t_obj.vehicle;
    loadCapacity = t_obj.loadCapacity;
    towingCapacity = t_obj.towingCapacity;
}

Truck& Truck::operator=(const Truck &t) {
    if (this != &t) {
        vehicle = t.vehicle;
        loadCapacity = t.loadCapacity;
        towingCapacity = t.towingCapacity;
    }
    return *this;
}

istream &operator>>(istream & is, Truck &t) {
    is >> t.vehicle;
    is >> t.loadCapacity;
    is >> t.towingCapacity;

    return is;
}

ostream &operator<<(ostream &os, const Truck &t) {
    os << t.vehicle << " ";
    os << t.loadCapacity << " ";
    os << t.towingCapacity;
    return os;
}
