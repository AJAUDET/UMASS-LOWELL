/*
    Author: AJ Audet
    Date: 10/1/2025
    Purpose: using boost to test our code
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
Date:   10/1/2025
Name:   AJ Audet
*/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE RationalTests

#include <boost/test/included/unit_test.hpp>
#include "Rational.hpp"
using namespace std;

BOOST_AUTO_TEST_CASE(testDefault)
{
    Rational r1;
    BOOST_REQUIRE_EQUAL(r1.getNum(), 0);
    BOOST_REQUIRE_EQUAL(r1.getDenom(), 1);
}

BOOST_AUTO_TEST_CASE(testConstructor)
{
    Rational r1(3, 4);
    BOOST_REQUIRE_EQUAL(r1.getNum(), 3);
    BOOST_REQUIRE_EQUAL(r1.getDenom(), 4);
}

BOOST_AUTO_TEST_CASE(testWhole)
{
    Rational r1(3);
    BOOST_REQUIRE_EQUAL(r1.getNum(), 3);
    BOOST_REQUIRE_EQUAL(r1.getDenom(), 1);
}

BOOST_AUTO_TEST_CASE(testInequalities)
{
    Rational a(1, 3);
    Rational b(1, 3);
    Rational c(1, 2);

    BOOST_REQUIRE_EQUAL(a.getNum(), 1);
    BOOST_REQUIRE_EQUAL(a.getDenom(), 3);
    BOOST_REQUIRE_EQUAL(b.getNum(), 1);
    BOOST_REQUIRE_EQUAL(b.getDenom(), 3);
    BOOST_REQUIRE_EQUAL(c.getNum(), 1);
    BOOST_REQUIRE_EQUAL(c.getDenom(), 2);

    BOOST_REQUIRE(a == b);
    BOOST_REQUIRE(!(a != b));

    BOOST_REQUIRE_NE(b, c);
    BOOST_REQUIRE(!(b == c));

    BOOST_REQUIRE_LT(a, c);
    BOOST_REQUIRE((a < c));

    BOOST_REQUIRE_LE(a, c);
    BOOST_REQUIRE(a <= c);

    BOOST_REQUIRE_GT(c, b);
    BOOST_REQUIRE(c > b);

    BOOST_REQUIRE_GE(c, b);
    BOOST_REQUIRE(c >= b);
}

BOOST_AUTO_TEST_CASE(testAddition)
{
    Rational r1(1, 3);
    Rational r2(2, 3);
    Rational r3(1, 1);
    Rational r4 = r1 + r2;
    BOOST_REQUIRE_EQUAL(r4, r3);
}

BOOST_AUTO_TEST_CASE(testAdditionMixed)
{
    Rational r1(1, 3);
    Rational r2(1, 6);
    BOOST_REQUIRE_EQUAL((r1 + r2).getNum(), 1);
    BOOST_REQUIRE_EQUAL((r1 + r2).getDenom(), 2);
}

BOOST_AUTO_TEST_CASE(testSubtraction)
{
    Rational r1(2, 3);
    Rational r2(1, 3);
    BOOST_REQUIRE_EQUAL((r1 - r2).getNum(), 1);
    BOOST_REQUIRE_EQUAL((r1 - r2).getDenom(), 3);
}

BOOST_AUTO_TEST_CASE(testSubtractionMixed)
{
    Rational r1(1, 2);
    Rational r2(1, 6);
    BOOST_REQUIRE_EQUAL((r1 - r2).getNum(), 1);
    BOOST_REQUIRE_EQUAL((r1 - r2).getDenom(), 3);
}

BOOST_AUTO_TEST_CASE(testMultiplication)
{
    Rational r1(1, 3);
    Rational r2(1, 3);
    Rational result = r1 * r2;
    BOOST_REQUIRE(result.getNum() == 1);
    BOOST_REQUIRE(result.getDenom() == 9);
}

BOOST_AUTO_TEST_CASE(testMixedMultiplication)
{
    Rational r1(1, 3);
    Rational r2(1, 2);
    Rational result = r1 * r2;
    BOOST_REQUIRE(result.getNum() == 1);
    BOOST_REQUIRE(result.getDenom() == 6);
}

BOOST_AUTO_TEST_CASE(testDivision)
{
    Rational r1(1, 3);
    Rational r2(1, 3);
    Rational result = r1 / r2;
    BOOST_REQUIRE(result.getNum() == 1);
    BOOST_REQUIRE(result.getDenom() == 1);
}

BOOST_AUTO_TEST_CASE(testMixedDivision)
{
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational result = r1 / r2;
    BOOST_REQUIRE(result.getNum() == 3);
    BOOST_REQUIRE(result.getDenom() == 2);
}

BOOST_AUTO_TEST_CASE(insertionOperator)
{
    Rational r3(5, 2);
    std::ostringstream oss_3;
    oss_3 << r3;
    BOOST_REQUIRE_EQUAL(oss_3.str(), "5/2");

    Rational r4(278);
    std::ostringstream oss_4;
    oss_4 << r4;
    BOOST_REQUIRE_EQUAL(oss_4.str(), "278/1");
}

BOOST_AUTO_TEST_CASE(extractionOperator)
{
    Rational r1;
    std::istringstream iss1("4/5");
    iss1 >> r1;
    BOOST_REQUIRE_EQUAL(r1.getNum(), 4);
    BOOST_REQUIRE_EQUAL(r1.getDenom(), 5);

    Rational r2;
    std::istringstream iss2("3/4");
    iss2 >> r2;
    BOOST_REQUIRE_EQUAL(r2.getNum(), 3);
    BOOST_REQUIRE_EQUAL(r2.getDenom(), 4);
}
