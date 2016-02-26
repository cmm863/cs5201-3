//////////////////////////////////////////////////////////////////////
/// @file qrdecomp.h
/// @author Connor McBride
/// @brief Contains the declaration information for the QRDecomp class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class QRDecomp
/// @brief Is a function class to implement the QRDecomp function
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn double QRDecomp::operator ()(const vector<Vector<T> > &A, vector<Vector<T> > &Q, vector<Vector<T> > &R) const
/// @brief Overloads the () operator to act as a function class.
/// @pre The type of T should be resolvable to a double. Vector should have a [] operator.
/// @post Q and R are decompositions of A
/// @param1 A holds a vector with type T
/// @param2 Q is empty
/// @param3 R is empty
//////////////////////////////////////////////////////////////////////

#ifndef QRDECOMP_H
#define QRDECOMP_H

#include "norm.h"
#include "vector.h"
#include <vector>

class QRDecomp
{
public:
  template <typename T>
  void operator ()(const vector<Vector<T> >& A, vector<Vector<T> >& Q, vector<Vector<T> >& R) const;
};

#include "qrdecomp.hpp"

#endif //QRDECOMP_H
