//////////////////////////////////////////////////////////////////////
/// @file norm.h
/// @author Connor McBride
/// @brief Contains the declaration information for the Norm class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class Norm
/// @brief Is a function class to implement the Norm function
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn double Norm::operator ()(const Vector<T> &pf, long p) const
/// @brief Overloads the () operator to act as a function class.
/// @pre The type of T should be resolvable to a float. Vector should have a [] operator.
/// @post Returns p-norm
/// @param v holds a vector with type T
/// @return Returns the p-norm norm
//////////////////////////////////////////////////////////////////////

#ifndef NORM_H
#define NORM_H

#include "vector.h"

class Norm
{
public:
  template <typename T>
     long double operator ()(const Vector<T>& v, long p) const;
};

#include "norm.hpp"

#endif //NORM_H
