#ifndef COUNTER_H
#define COUNTER_H

#include <cstddef>

namespace Utils
{
	class Generator;
}

class Counter
{
public:
	Counter(Utils::Generator* generator, size_t limit);

	void operator()();

private:
	Utils::Generator* Generator_;
	size_t Count_;
};

#endif//COUNTER_H
