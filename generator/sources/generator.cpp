#include "../generator.h"

Utils::Generator::Generator()
	: Value_(0)
{
}

size_t Utils::Generator::operator()()
{
	boost::mutex::scoped_lock lock(Mutex_);
	++Value_;
	return Value_;
}
