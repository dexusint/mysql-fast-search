#include "../calculator.h"

#define BOOST_TEST_MODULE testCalculator
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

const double VALUE = 5.0;
const double TOLERANCE = 0.001;

struct Fixture
{
	Fixture()
		: calculator(VALUE)
	{
		BOOST_TEST_MESSAGE("Setup fixture");
	}

	~Fixture()
	{
		BOOST_TEST_MESSAGE("Teardown fixture");
	}

	Utils::Calculator calculator;
};

BOOST_FIXTURE_TEST_CASE(testCalculatorAdd, Fixture)
{
	BOOST_CHECK_CLOSE(calculator.Result(), VALUE, TOLERANCE);
	calculator.Add(VALUE);
	BOOST_CHECK_CLOSE(calculator.Result(), VALUE + VALUE, TOLERANCE);
}

BOOST_FIXTURE_TEST_CASE(testCalculatorSubtract, Fixture)
{
	BOOST_CHECK_CLOSE(calculator.Result(), VALUE, TOLERANCE);
	calculator.Subtract(VALUE);
	BOOST_CHECK_CLOSE(calculator.Result(), VALUE - VALUE, TOLERANCE);
}
