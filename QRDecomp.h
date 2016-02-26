//////////////////////////////////////////////////////////////////////
/// @file qrdecomp.h
/// @author Connor McBride
/// @brief Contains the declaration information for the QRDecomp class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class QRDecomp
/// @brief Is a function class to implement the QRDecomp function
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
