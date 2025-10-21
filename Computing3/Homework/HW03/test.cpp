/*
    Author: AJ Audet
    Date: 9/28/2025
    Purpose: using boost to test our code 
    Time Spent: 45 mins coding, 2 hours debugging boost
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
Date:   9/28/2025
Name:   AJ Audet
*/

// This uses the Boost Unit Test Framework
// https://www.boost.org/library/latest/test/
// On Debian/Ubuntu you can install this with the command
// sudo apt install libboost-test-dev

// Tells Boost to make a main for you
#define BOOST_TEST_DYN_LINK
// Name of the test module
#define BOOST_TEST_MODULE PointTests
// Load the testing library.  This must come after the previous two macros
// #include <boost/test/unit_test.hpp>
// For Mac: you may need to use #include <boost/test/included/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>

// Load the unit to be tested
#include "Point.hpp"

/**
 * Sample test case to get you started
 * You can define new tests using the BOOST_AUTO_TEST_CASE macro
 */
BOOST_AUTO_TEST_CASE(testConstructor) {
    // Object under test
    Point pt(2, 4);
    // Test assertions to make sure the object behaves correctly
    BOOST_REQUIRE_EQUAL(pt.getX(), 2);
    BOOST_REQUIRE_EQUAL(pt.getY(), 4);
}

BOOST_AUTO_TEST_CASE(testDefault) {
    Point pt;
    BOOST_REQUIRE_EQUAL(pt.getX(), 0);
    BOOST_REQUIRE_EQUAL(pt.getY(), 0);
}

BOOST_AUTO_TEST_CASE(testMutator) {
    Point pt;
    pt.setX(5);
    pt.setY(7);
    BOOST_REQUIRE_EQUAL(pt.getX(), 5);
    BOOST_REQUIRE_EQUAL(pt.getY(), 7);
}

BOOST_AUTO_TEST_CASE(testClockwise) {
    Point pt(4, 3);
    pt.rotateCW();
    BOOST_REQUIRE_EQUAL(pt.getX(), 3);
    BOOST_REQUIRE_EQUAL(pt.getY(), -4);
}

BOOST_AUTO_TEST_CASE(testCounterClockwise) {
    Point pt(6, 7);
    pt.rotateCCW();
    BOOST_REQUIRE_EQUAL(pt.getX(), -7);
    BOOST_REQUIRE_EQUAL(pt.getY(), 6);
}

BOOST_AUTO_TEST_CASE(testMovers)
{
    Point pt(3, 2);
    pt.move(4, 5);
    BOOST_REQUIRE_EQUAL(pt.getX(), 7);
    BOOST_REQUIRE_EQUAL(pt.getY(), 7);
}
