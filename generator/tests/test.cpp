#include "../generator.h"

#define BOOST_TEST_MODULE testGenerator
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testGenerator)
{
	Utils::Generator<1, 10> generator;
	auto value = generator();
	BOOST_CHECK(value > 1 && value < 10);
}
