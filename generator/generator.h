#ifndef GENERATOR_H
#define GENERATOR_H

#include <cstddef>
#include <cstdlib>
#include <ctime>

using std::size_t;

namespace Utils
{
template <size_t lowerBound, size_t upperBound>
class Generator
{
public:
  Generator() {
    srand(time(0));
  }
  size_t operator()();
};

template <size_t lowerBound, size_t upperBound>
size_t Generator<lowerBound, upperBound>::operator()() {
  return ((double)rand() / RAND_MAX) * (upperBound - lowerBound);
}

}

#endif//GENERATOR_H
