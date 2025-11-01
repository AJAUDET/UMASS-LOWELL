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
#include "Person.hpp"

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

BOOST_AUTO_TEST_CASE(testInsertion)
{
    Person p1;
    cout << "Whats your name: ";
    cin >> p1;
    cout << endl << p1.getName();
}
