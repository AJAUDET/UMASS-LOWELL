#define BOOST_TEST_MODULE iterator
#include <boost/test/included/unit_test.hpp>
#include <numeric>
#include <vector>

struct test_fixture {
  std::vector<int> data;
  test_fixture(): data(20) { std::iota(data.begin(), data.end(), 0); }
};

BOOST_AUTO_TEST_CASE(verify_fixture) {
  test_fixture tf;
  int start = 0;
  for (const auto& i : tf.data) {
    BOOST_TEST(i == start++);
  }
}