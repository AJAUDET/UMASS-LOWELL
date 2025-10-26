/*
    Author: AJ Audet
    Date: 10/26/2025
    Purpose: using boost to test our dynamic string code
    Time Spent: 2.5 hrs
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
Date:   10/26/2025
Name:   AJ Audet
*/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE DynamicStringArrayTests
#include <boost/test/included/unit_test.hpp>
#include "DynamicStringArray.hpp"

BOOST_AUTO_TEST_CASE(test_default_constructor)
{
    DynamicStringArray arr;
    BOOST_REQUIRE_EQUAL(arr.getSize(), 0);
}

BOOST_AUTO_TEST_CASE(test_getSize)
{
    DynamicStringArray arr;
    BOOST_REQUIRE_EQUAL(arr.getSize(), 0);

    arr.addEntry("first");
    BOOST_REQUIRE_EQUAL(arr.getSize(), 1);

    arr.addEntry("second");
    BOOST_REQUIRE_EQUAL(arr.getSize(), 2);
}

BOOST_AUTO_TEST_CASE(test_addEntry)
{
    DynamicStringArray arr;

    arr.addEntry("apple");
    BOOST_REQUIRE_EQUAL(arr.getSize(), 1);

    arr.addEntry("banana");
    BOOST_REQUIRE_EQUAL(arr.getSize(), 2);

    arr.addEntry("cherry");
    BOOST_REQUIRE_EQUAL(arr.getSize(), 3);
}

BOOST_AUTO_TEST_CASE(test_getEntry_valid)
{
    DynamicStringArray arr;
    arr.addEntry("first");
    arr.addEntry("second");
    arr.addEntry("third");

    string *ptr = arr.getEntry(0);
    BOOST_REQUIRE(ptr != nullptr);
    BOOST_REQUIRE_EQUAL(*ptr, "first");

    ptr = arr.getEntry(1);
    BOOST_REQUIRE(ptr != nullptr);
    BOOST_REQUIRE_EQUAL(*ptr, "second");

    ptr = arr.getEntry(2);
    BOOST_REQUIRE(ptr != nullptr);
    BOOST_REQUIRE_EQUAL(*ptr, "third");
}

BOOST_AUTO_TEST_CASE(test_getEntry_invalid)
{
    DynamicStringArray arr;
    arr.addEntry("test");

    BOOST_REQUIRE(arr.getEntry(-1) == nullptr);
    BOOST_REQUIRE(arr.getEntry(1) == nullptr);
    BOOST_REQUIRE(arr.getEntry(100) == nullptr);

    DynamicStringArray emptyArr;
    BOOST_REQUIRE(emptyArr.getEntry(0) == nullptr);
}

BOOST_AUTO_TEST_CASE(test_deleteEntry_exists)
{
    DynamicStringArray arr;
    arr.addEntry("apple");
    arr.addEntry("banana");
    arr.addEntry("cherry");

    bool result = arr.deleteEntry("banana");
    BOOST_REQUIRE_EQUAL(result, true);
    BOOST_REQUIRE_EQUAL(arr.getSize(), 2);

    BOOST_REQUIRE_EQUAL(*arr.getEntry(0), "apple");
    BOOST_REQUIRE_EQUAL(*arr.getEntry(1), "cherry");
}

BOOST_AUTO_TEST_CASE(test_deleteEntry_not_exists)
{
    DynamicStringArray arr;
    arr.addEntry("apple");
    arr.addEntry("banana");

    bool result = arr.deleteEntry("orange");
    BOOST_REQUIRE_EQUAL(result, false);
    BOOST_REQUIRE_EQUAL(arr.getSize(), 2);
}

BOOST_AUTO_TEST_CASE(test_deleteEntry_last_element)
{
    DynamicStringArray arr;
    arr.addEntry("only");

    bool result = arr.deleteEntry("only");
    BOOST_REQUIRE_EQUAL(result, true);
    BOOST_REQUIRE_EQUAL(arr.getSize(), 0);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor)
{
    DynamicStringArray arr1;
    arr1.addEntry("first");
    arr1.addEntry("second");
    arr1.addEntry("third");

    DynamicStringArray arr2(arr1);

    BOOST_REQUIRE_EQUAL(arr2.getSize(), 3);

    BOOST_REQUIRE_EQUAL(*arr2.getEntry(0), "first");
    BOOST_REQUIRE_EQUAL(*arr2.getEntry(1), "second");
    BOOST_REQUIRE_EQUAL(*arr2.getEntry(2), "third");

    BOOST_REQUIRE(arr1.getEntry(0) != arr2.getEntry(0));

    arr1.addEntry("fourth");
    BOOST_REQUIRE_EQUAL(arr1.getSize(), 4);
    BOOST_REQUIRE_EQUAL(arr2.getSize(), 3);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor_empty)
{
    DynamicStringArray arr1;
    DynamicStringArray arr2(arr1);

    BOOST_REQUIRE_EQUAL(arr2.getSize(), 0);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment)
{
    DynamicStringArray arr1;
    arr1.addEntry("alpha");
    arr1.addEntry("beta");

    DynamicStringArray arr2;
    arr2.addEntry("gamma");

    arr2 = arr1;

    BOOST_REQUIRE_EQUAL(arr2.getSize(), 2);

    BOOST_REQUIRE_EQUAL(*arr2.getEntry(0), "alpha");
    BOOST_REQUIRE_EQUAL(*arr2.getEntry(1), "beta");

    BOOST_REQUIRE(arr1.getEntry(0) != arr2.getEntry(0));

    arr1.deleteEntry("alpha");
    BOOST_REQUIRE_EQUAL(arr1.getSize(), 1);
    BOOST_REQUIRE_EQUAL(arr2.getSize(), 2);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment_self)
{
    DynamicStringArray arr;
    arr.addEntry("test");

    arr = arr;

    BOOST_REQUIRE_EQUAL(arr.getSize(), 1);
    BOOST_REQUIRE_EQUAL(*arr.getEntry(0), "test");
}

BOOST_AUTO_TEST_CASE(test_destructor)
{
    DynamicStringArray *arr = new DynamicStringArray();
    arr->addEntry("test1");
    arr->addEntry("test2");
    delete arr;
    BOOST_REQUIRE(true);
}