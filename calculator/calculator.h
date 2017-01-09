#ifndef CALCULATOR_H
#define CALCULATOR_H

namespace Utils
{
	class Calculator
	{
	public:
		explicit Calculator(double value);

		void Add(double value);
		void Subtract(double value);

		double Result() const;

	private:
		double Value_;
	};
}

#endif//CALCULATOR_H
