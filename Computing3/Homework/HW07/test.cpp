/*
    Author: AJ Audet
    Date: 11/1/2025
    Purpose: using inheritance to test the classes Vehicle and Person
    Time Spent: 2 hours
*/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University's Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date:   11/1/2025
Name:   AJ Audet
*/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE DynamicStringArrayTests
#include <string>
#include <iostream>
#include <boost/test/unit_test.hpp>
#include "Vehicle.hpp"
using namespace std;

BOOST_AUTO_TEST_CASE(testPersonDEFAULT) {
    Person p1;
    BOOST_REQUIRE_EQUAL(p1.getName(), "none");
}

BOOST_AUTO_TEST_CASE(testPersonVALUE) {
    Person p2("Bob");
    BOOST_REQUIRE_EQUAL(p2.getName(), "Bob");
}

BOOST_AUTO_TEST_CASE(testPersonCOPY) {
    Person p2("Bob");
    Person p3(p2);
    BOOST_REQUIRE_EQUAL(p3.getName(), p2.getName());
}

BOOST_AUTO_TEST_CASE(testPersonGETTER) {
    Person p1;
    p1.getName();
}

BOOST_AUTO_TEST_CASE(testPersonASSIGNMENT) {
    Person p2("Bob");
    Person p3 = p2;
    BOOST_REQUIRE_EQUAL(p3.getName(), p2.getName());
}

BOOST_AUTO_TEST_CASE(testPersonInsertion) {
    string name;
    cout << "What's your name: ";
    getline(cin, name);
    Person p1(name);
    cout << p1 << endl;
}

BOOST_AUTO_TEST_CASE(testVehicleDEFAULT) {
    Vehicle v1;
    BOOST_REQUIRE_EQUAL(v1.getOwner(), "none");
    BOOST_REQUIRE_EQUAL(v1.numCylinders(), 0);
    BOOST_REQUIRE_EQUAL(v1.getManufacturer(), "none");
}

BOOST_AUTO_TEST_CASE(testVehicleVALUE) {
    Person p1("Bob");
    Vehicle v1(p1, 3, "Ford");
    BOOST_REQUIRE_EQUAL(v1.getOwner(), "Bob");
    BOOST_REQUIRE_EQUAL(v1.numCylinders(), 3);
    BOOST_REQUIRE_EQUAL(v1.getManufacturer(), "Ford");
}

BOOST_AUTO_TEST_CASE(testVehicleCOPY) {
    Person p1("Bob");
    Vehicle v1(p1, 3, "Ford");
    Vehicle v2(v1);
    BOOST_REQUIRE_EQUAL(v2.getOwner(), v1.getOwner());
    BOOST_REQUIRE_EQUAL(v2.numCylinders(), v1.numCylinders());
    BOOST_REQUIRE_EQUAL(v2.getManufacturer(), v1.getManufacturer());
}

BOOST_AUTO_TEST_CASE(testVehicleASSIGNMENT) {
    Person p1("Bob");
    Vehicle v1(p1, 3, "Ford");
    Vehicle v2 = v1;
    BOOST_REQUIRE_EQUAL(v2.getOwner(), v1.getOwner());
    BOOST_REQUIRE_EQUAL(v2.numCylinders(), v1.numCylinders());
    BOOST_REQUIRE_EQUAL(v2.getManufacturer(), v1.getManufacturer());
}

BOOST_AUTO_TEST_CASE(testVehicleGETTER) {
    Vehicle v1;
    v1.getOwner();
    v1.numCylinders();
    v1.getManufacturer();
}

BOOST_AUTO_TEST_CASE(testVehicleInsertion) {
    string owner;
    string manufacturer;
    int cylinders;
    cout << "What's your name: ";
    getline(cin, owner);
    Person p1(owner);

    cout << "How many cylinders does your engine have: ";
    cin >> cylinders;

    cout << "What is your vehicle's manufacturer: ";
    cin >> manufacturer;
    Vehicle v1(p1, cylinders, manufacturer);
    cout << v1 << endl;
}

BOOST_AUTO_TEST_CASE(testTruckDEFAULT) {
    Truck t;
    BOOST_REQUIRE_EQUAL(t.getOwner(), "none");
    BOOST_REQUIRE_EQUAL(t.numCylinders(), 0);
    BOOST_REQUIRE_EQUAL(t.getManufacturer(), "none");
    BOOST_REQUIRE_EQUAL(t.getLoadCapacity(), 0.0);
    BOOST_REQUIRE_EQUAL(t.getTowingCapacity(), 0);
}

BOOST_AUTO_TEST_CASE(testTruckVALUE) {
    Person p("Bob");
    Vehicle v(p, 3, "Ford");
    Truck t(v, 1000.1, 35);
    BOOST_REQUIRE_EQUAL(t.getOwner(), "Bob");
    BOOST_REQUIRE_EQUAL(t.numCylinders(), 3);
    BOOST_REQUIRE_EQUAL(t.getManufacturer(), "Ford");
    BOOST_REQUIRE_EQUAL(t.getLoadCapacity(), 1000.1);
    BOOST_REQUIRE_EQUAL(t.getTowingCapacity(), 35);
}

BOOST_AUTO_TEST_CASE(testTruckCOPY) {
    Person p("Bob");
    Vehicle v(p, 3, "Ford");
    Truck t1(v, 1000.1, 35);
    Truck t2(t1);
    BOOST_REQUIRE_EQUAL(t2.getOwner(), t1.getOwner());
    BOOST_REQUIRE_EQUAL(t2.numCylinders(), t1.numCylinders());
    BOOST_REQUIRE_EQUAL(t2.getManufacturer(), t1.getManufacturer());
    BOOST_REQUIRE_EQUAL(t2.getLoadCapacity(), t1.getLoadCapacity());
    BOOST_REQUIRE_EQUAL(t2.getTowingCapacity(), t1.getTowingCapacity());
}

BOOST_AUTO_TEST_CASE(testTruckASSIGNMENT) {
    Person p("Bob");
    Vehicle v(p, 3, "Ford");
    Truck t1(v, 1000.1, 35);
    Truck t2 = t1;
    BOOST_REQUIRE_EQUAL(t2.getOwner(), t1.getOwner());
    BOOST_REQUIRE_EQUAL(t2.numCylinders(), t1.numCylinders());
    BOOST_REQUIRE_EQUAL(t2.getManufacturer(), t1.getManufacturer());
    BOOST_REQUIRE_EQUAL(t2.getLoadCapacity(), t1.getLoadCapacity());
    BOOST_REQUIRE_EQUAL(t2.getTowingCapacity(), t1.getTowingCapacity());
}

BOOST_AUTO_TEST_CASE(testTruckGETTERS) {
    Truck t;
    t.getLoadCapacity();
    t.getTowingCapacity();
}

BOOST_AUTO_TEST_CASE(testTruckINSERTION) {
    string owner;
    string manufacturer;
    int cylinders, tow;
    double load;
    cout << "What's your name: ";
    getline(cin, owner);
    Person p1(owner);
    cout << endl;

    cout << "How many cylinders does your engine have: ";
    cin >> cylinders;
    cout << endl;

    cout << "What is your vehicle's manufacturer: ";
    cin >> manufacturer;
    Vehicle v1(p1, cylinders, manufacturer);
    cout << endl;

    cout << "What is your Truck's load capacity: ";
    cin >> load;
    cout << endl;

    cout << "What is your Truck's towing capacity: ";
    cin >> tow;
    cout << endl;
    Truck t(v1, load, tow);

    cout << t << endl;
}
