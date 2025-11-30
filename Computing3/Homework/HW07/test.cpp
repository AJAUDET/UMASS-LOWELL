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
#define BOOST_TEST_MODULE VehicleAndTruckTests

#include <boost/test/unit_test.hpp>
#include <string>
#include <iostream>
#include "Vehicle.hpp"
using namespace std;

// ===== Person Tests =====

BOOST_AUTO_TEST_CASE(testPersonDefault)
{
    Person p;
    BOOST_REQUIRE_EQUAL(p.getName(), "none");
}

BOOST_AUTO_TEST_CASE(testPersonValue)
{
    Person p("Nous");
    BOOST_REQUIRE_EQUAL(p.getName(), "Nous");
}

BOOST_AUTO_TEST_CASE(testPersonCopy)
{
    Person p1("Nanook");
    Person p2(p1);
    BOOST_REQUIRE_EQUAL(p2.getName(), "Nanook");
}

BOOST_AUTO_TEST_CASE(testPersonAssign)
{
    Person p1("Mythus");
    Person p2;
    p2 = p1;
    BOOST_REQUIRE_EQUAL(p2.getName(), "Mythus");
}

// ===== Vehicle Tests =====

BOOST_AUTO_TEST_CASE(testVehicleDefault)
{
    Vehicle v;
    BOOST_REQUIRE_EQUAL(v.getOwner().getName(), "none");
    BOOST_REQUIRE_EQUAL(v.getNumCylinders(), 0);
    BOOST_REQUIRE_EQUAL(v.getManufacturer(), "none");
}

BOOST_AUTO_TEST_CASE(testVehicleValue)
{
    Person p("Aha");
    Vehicle v(p, 4, "Toyota");
    BOOST_REQUIRE_EQUAL(v.getOwner().getName(), "Aha");
    BOOST_REQUIRE_EQUAL(v.getNumCylinders(), 4);
    BOOST_REQUIRE_EQUAL(v.getManufacturer(), "Toyota");
}

BOOST_AUTO_TEST_CASE(testVehicleCopy)
{
    Person p("Fuli");
    Vehicle v1(p, 6, "Ford");
    Vehicle v2(v1);

    BOOST_REQUIRE_EQUAL(v2.getOwner().getName(), "Fuli");
    BOOST_REQUIRE_EQUAL(v2.getNumCylinders(), 6);
    BOOST_REQUIRE_EQUAL(v2.getManufacturer(), "Ford");
}

BOOST_AUTO_TEST_CASE(testVehicleAssign)
{
    Person p("Eve");
    Vehicle v1(p, 8, "Honda");
    Vehicle v2;
    v2 = v1;

    BOOST_REQUIRE_EQUAL(v2.getOwner().getName(), "Eve");
    BOOST_REQUIRE_EQUAL(v2.getNumCylinders(), 8);
    BOOST_REQUIRE_EQUAL(v2.getManufacturer(), "Honda");
}

BOOST_AUTO_TEST_CASE(testVehicleInsertion)
{
    Person p("Frank");
    Vehicle v(p, 3, "Nissan");
    ostringstream out;
    out << v;
    BOOST_TEST_MESSAGE("Vehicle output: " << out.str());
    BOOST_REQUIRE(out.str().find("Frank") != string::npos);
    BOOST_REQUIRE(out.str().find("Nissan") != string::npos);
}

// ===== Truck Tests =====

BOOST_AUTO_TEST_CASE(testTruckDefault)
{
    Truck t;
    BOOST_REQUIRE_EQUAL(t.getOwner().getName(), "none");
    BOOST_REQUIRE_EQUAL(t.getNumCylinders(), 0);
    BOOST_REQUIRE_EQUAL(t.getManufacturer(), "none");
    BOOST_REQUIRE_EQUAL(t.getLoadCapacity(), 0.0);
    BOOST_REQUIRE_EQUAL(t.getTowingCapacity(), 0);
}

BOOST_AUTO_TEST_CASE(testTruckValue)
{
    Person p("Nous");
    Vehicle v(p, 6, "Ford");
    Truck t(v, 2500.5, 9000);

    BOOST_REQUIRE_EQUAL(t.getOwner().getName(), "Nous");
    BOOST_REQUIRE_EQUAL(t.getNumCylinders(), 6);
    BOOST_REQUIRE_EQUAL(t.getManufacturer(), "Ford");
    BOOST_REQUIRE_EQUAL(t.getLoadCapacity(), 2500.5);
    BOOST_REQUIRE_EQUAL(t.getTowingCapacity(), 9000);
}

BOOST_AUTO_TEST_CASE(testTruckCopy)
{
    Person p("Aha");
    Vehicle v(p, 8, "Chevy");
    Truck t1(v, 3000.0, 10000);
    Truck t2(t1);

    BOOST_REQUIRE_EQUAL(t2.getLoadCapacity(), 3000.0);
    BOOST_REQUIRE_EQUAL(t2.getTowingCapacity(), 10000);
}

BOOST_AUTO_TEST_CASE(testTruckAssign)
{
    Person p("Tazzyroth");
    Vehicle v(p, 6, "Ram");
    Truck t1(v, 1500.0, 5000);
    Truck t2;
    t2 = t1;

    BOOST_REQUIRE_EQUAL(t2.getLoadCapacity(), 1500.0);
    BOOST_REQUIRE_EQUAL(t2.getTowingCapacity(), 5000);
}

BOOST_AUTO_TEST_CASE(testTruckInsertion)
{
    Person p("HooH");
    Vehicle v(p, 4, "GMC");
    Truck t(v, 2000.0, 6000);
    ostringstream out;
    out << t;
    BOOST_TEST_MESSAGE("Truck output: " << out.str());
    BOOST_REQUIRE(out.str().find("HooH") != string::npos);
    BOOST_REQUIRE(out.str().find("GMC") != string::npos);
}