#define BOOST_TEST_MODULE SampleTests
#include <money.cpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(constructor_getters)
{
    // default construcor
    Money m;
    BOOST_REQUIRE_EQUAL(m.get_dollars() == 0);
    BOOST_REQUIRE_EQUAL(m.get_cents() == 0);
}