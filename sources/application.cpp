#include <cassert>
#include <iostream>

#include <generator/generator.h>

#include <includes/application.h>

//Counter::Counter(Utils::Generator* generator, size_t limit)
//	: Generator_(generator)
//	, Count_(limit)
//{
//	assert(Generator_);
//}
//
//void Counter::operator()()
//{
//	std::cout << "Thread started" << std::endl;
//	size_t value = 0;
//	while (value < Count_)
//	{
//		value = (*Generator_)();
//		if (Count_ >= value)
//		{
//			Count_ -= value;
//		}
//	}
//	std::cout << "Thread finished" << std::endl;
//}
