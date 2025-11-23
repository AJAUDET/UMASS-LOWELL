/*
    Author: AJ Audet
    Date: 11/21/2025
    Purpose: adding and testing throw exceptions for the pre defined PFArrayD class
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
Date:   11/21/2025
Name:   AJ Audet
*/

#define BOOST_TEST_MODULE PFArrayD_Tests
#include <boost/test/included/unit_test.hpp>

#include "PFArrayD.hpp"
#include "OutOfRange.hpp"

BOOST_AUTO_TEST_CASE(test_default_constructor) {
    PFArrayD arr;

    BOOST_REQUIRE_EQUAL(arr.getCapacity(), 50);
    BOOST_REQUIRE_EQUAL(arr.getSize(), 0);
    BOOST_REQUIRE_NO_THROW(arr.addElement(1.0));
}

BOOST_AUTO_TEST_CASE(test_custom_constructor) {
    PFArrayD arr(5);

    BOOST_REQUIRE_EQUAL(arr.getCapacity(), 5);
    BOOST_REQUIRE_EQUAL(arr.getSize(), 0);
}

BOOST_AUTO_TEST_CASE(test_addElement_valid) {
    PFArrayD arr(3);

    BOOST_REQUIRE_NO_THROW(arr.addElement(1.1));
    BOOST_REQUIRE_NO_THROW(arr.addElement(2.2));
    BOOST_REQUIRE_EQUAL(arr.getSize(), 2);
}

BOOST_AUTO_TEST_CASE(test_addElement_out_of_range) {
    PFArrayD arr(1);

    BOOST_REQUIRE_NO_THROW(arr.addElement(3.14));

    BOOST_REQUIRE_THROW(arr.addElement(2.71), OutOfRange);
}

BOOST_AUTO_TEST_CASE(test_operator_index_valid) {
    PFArrayD arr(2);

    arr.addElement(10.0);
    arr.addElement(20.0);

    BOOST_REQUIRE_NO_THROW(arr[0]);
    BOOST_REQUIRE_NO_THROW(arr[1]);

    BOOST_REQUIRE_EQUAL(arr[0], 10.0);
    BOOST_REQUIRE_EQUAL(arr[1], 20.0);
}

BOOST_AUTO_TEST_CASE(test_operator_index_invalid) {
    PFArrayD arr(2);
    arr.addElement(5.0);

    BOOST_REQUIRE_THROW(arr[1], OutOfRange);

    BOOST_REQUIRE_THROW(arr[-1], OutOfRange);
}

BOOST_AUTO_TEST_CASE(test_clearArray) {
    PFArrayD arr(3);
    arr.addElement(1.0);
    arr.addElement(2.0);

    arr.clearArray();

    BOOST_REQUIRE_EQUAL(arr.getSize(), 0);

    BOOST_REQUIRE_NO_THROW(arr.addElement(3.0));
}

BOOST_AUTO_TEST_CASE(test_copy_constructor) {
    PFArrayD original(3);
    original.addElement(1.0);
    original.addElement(2.0);

    PFArrayD copy = original;

    BOOST_REQUIRE_EQUAL(copy.getSize(), 2);
    BOOST_REQUIRE_EQUAL(copy[0], 1.0);
    BOOST_REQUIRE_EQUAL(copy[1], 2.0);
    copy[0] = 99.0;
    BOOST_REQUIRE_EQUAL(original[0], 1.0);
}

BOOST_AUTO_TEST_CASE(test_assignment_operator) {
    PFArrayD a(3);
    a.addElement(4.0);
    a.addElement(5.0);

    PFArrayD b(10);

    b = a;

    BOOST_REQUIRE_EQUAL(b.getSize(), 2);
    BOOST_REQUIRE_EQUAL(b[0], 4.0);
    BOOST_REQUIRE_EQUAL(b[1], 5.0);

    b[0] = 100.0;
    BOOST_REQUIRE_EQUAL(a[0], 4.0);
}
