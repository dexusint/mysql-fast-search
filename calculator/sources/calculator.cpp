#include "../calculator.h"

Utils::Calculator::Calculator(double value)
	: Value_(value)
{
}

void Utils::Calculator::Add(double value)
{
	Value_ += value;
}

void Utils::Calculator::Subtract(double value)
{
	Value_ -= value;
}

double Utils::Calculator::Result() const
{
	return Value_;
}
