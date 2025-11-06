/*
    Author: AJ Audet
    Date: 11/1/2025
    Purpose: using inheritance to test the classes Vehicle and Person
    Time Spent: 
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
#include <boost/test/unit_test.hpp>
#include "Vehicle.hpp"
#include <string>
using namespace std;

BOOST_AUTO_TEST_CASE(testPersonDEFAULT)
{
    Person p1;
    BOOST_REQUIRE_EQUAL(p1.getName(), "none");
}

BOOST_AUTO_TEST_CASE(testPersonVALUE)
{
    Person p2("Bob");
    BOOST_REQUIRE_EQUAL(p2.getName(), "Bob");
}

BOOST_AUTO_TEST_CASE(testPersonCOPY)
{
    Person p2("Bob");
    Person p3(p2);
    BOOST_REQUIRE_EQUAL(p3.getName(), p2.getName());
}

BOOST_AUTO_TEST_CASE(testPersonGETTER)
{
    Person p1;
    p1.getName();
}

BOOST_AUTO_TEST_CASE(testPersonASSIGNMENT)
{
    Person p2("Bob");
    Person p3 = p2;
    BOOST_REQUIRE_EQUAL(p3.getName(), p2.getName());
}

BOOST_AUTO_TEST_CASE(testPersonInsertion)
{
    string name;
    cout << "What's your name: ";
    getline(cin, name);
    Person p1(name);
    cout << p1 << endl;
}

BOOST_AUTO_TEST_CASE(testVehicleDEFAULT)
{
    Vehicle v1;
    BOOST_REQUIRE_EQUAL(v1.getOwner(), "none");
    BOOST_REQUIRE_EQUAL(v1.numCylinders(), 0);
    BOOST_REQUIRE_EQUAL(v1.getManufacturer(), "none");
}

BOOST_AUTO_TEST_CASE(testVehicleVALUE)
{
    Person p1("Bob");
    Vehicle v1(p1, 3, "Ford");
    BOOST_REQUIRE_EQUAL(v1.getOwner(), "Bob");
    BOOST_REQUIRE_EQUAL(v1.numCylinders(), 3);
    BOOST_REQUIRE_EQUAL(v1.getManufacturer(), "Ford");
}

BOOST_AUTO_TEST_CASE(testVehicleCOPY)
{
    Person p1("Bob");
    Vehicle v1(p1, 3, "Ford");
    Vehicle v2(v1);
    BOOST_REQUIRE_EQUAL(v2.getOwner(), v1.getOwner());
    BOOST_REQUIRE_EQUAL(v2.numCylinders(), v1.numCylinders());
    BOOST_REQUIRE_EQUAL(v2.getManufacturer(), v1.getManufacturer());
}

BOOST_AUTO_TEST_CASE(testVehicleGETTER)
{
    Vehicle v1;
    v1.getOwner();
    v1.numCylinders();
    v1.getManufacturer();
}

BOOST_AUTO_TEST_CASE(testVehicleInsertion)
{
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
