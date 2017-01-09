#include "../generator.h"

#define BOOST_TEST_MODULE testGenerator
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testGenerator)
{
	Utils::Generator generator;
	for (size_t n = 1; n <= 10; ++n)
	{
		BOOST_CHECK_EQUAL(n, generator());
	}
}
