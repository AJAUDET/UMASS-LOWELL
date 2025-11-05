#include "Vehicle.hpp"

Vehicle::Vehicle()
{
    owner = Person();
    cylinders = 0;
    manufacturer = "none";
}

Vehicle::Vehicle(Person new_owner, int new_cylinders, string new_manufacturer)
{
    owner = new_owner;
    cylinders = new_cylinders;
    manufacturer = new_manufacturer;
}

Vehicle::Vehicle(const Vehicle &v_obj)
{
    owner = v_obj.owner;
    cylinders = v_obj.cylinders;
    manufacturer = v_obj.manufacturer;
}

string Vehicle::getOwner()
{
    return owner.getName();
}

int Vehicle::getCylinders()
{
    return cylinders;
}

string Vehicle::getManufacturer()
{
    return manufacturer;
}

istream& operator >>(istream& is, Vehicle& obj)
{
    is >> obj.owner;
    is >> obj.cylinders;
    is >> obj.manufacturer;
    return is;
}

ostream& operator <<(ostream& os, const Vehicle& obj)
{
    os << obj.owner << " ";
    os << obj.cylinders << " ";
    os << obj.manufacturer;
    return os;
}
