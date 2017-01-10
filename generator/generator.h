#ifndef GENERATOR_H
#define GENERATOR_H

#include <cstddef>
#include <cstdlib>
#include <ctime>

using std::size_t;

namespace Utils
{
template <typename T>
class Generator
{
public:
  Generator(T lowerBound, T upperBound):
    m_lowerBound(lowerBound),
    m_upperBound(upperBound)
  {
    srand(time(0));
  }
  T operator()();
private:
  T m_lowerBound;
  T m_upperBound;
};

template <typename T>
T Generator<T>::operator()() {
  return ((double)rand() / RAND_MAX) * (m_upperBound - m_lowerBound) + m_lowerBound;
}

}

#endif//GENERATOR_H
