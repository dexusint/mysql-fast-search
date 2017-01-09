#ifndef GENERATOR_H
#define GENERATOR_H

#include <cstddef>

#include <boost/noncopyable.hpp>
#include <boost/thread/mutex.hpp>

namespace Utils
{
	class Generator
		: private boost::noncopyable
	{
	public:
		Generator();

		size_t operator()();

	private:
		size_t Value_;
		boost::mutex Mutex_;
	};
}

#endif//GENERATOR_H
