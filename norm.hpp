//////////////////////////////////////////////////////////////////////
/// @file norm.hpp
/// @author Connor McBride
/// @brief Contains the norm class implementation information
//////////////////////////////////////////////////////////////////////

#ifndef NORM_HPP
#define NORM_HPP

#include "norm.h"
#include "vector.h"
#include <cmath>

template <typename T>
long double Norm::operator()(const Vector<T> &v, long p) const
{
  long double sum = 0;
  for(unsigned long i = 0; i < v.capacity(); i++)
  {
    sum += pow(abs(v[i]), p);
  }

  return pow(sum, 1.0/p);
}

#endif //NORM_HPP
