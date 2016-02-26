//////////////////////////////////////////////////////////////////////
/// @file qrdecomp.hpp
/// @author Connor McBride
/// @brief Contains the QRDecomp class implementation information
//////////////////////////////////////////////////////////////////////

#ifndef QRDECOMP_HPP
#define QRDECOMP_HPP

#include "vector.h"
#include <vector>
#include "norm.h"
#include "qrdecomp.h"

template <typename T>
void QRDecomp::operator()(const vector<Vector<T> > &A, vector<Vector<T> > &Q, vector<Vector<T> > &R) const
{
  Norm n2;
  long double ld_temp;
  double constant;
  Vector<T> * offset;
  Vector<T> * orthogonalized;
  Vector<T> * temp;
  for(unsigned long k = 0; k < A.capacity(); k++)
  {
    for(unsigned long i = 0; i < k; i++)
    {
      ld_temp = A[k] * Q[i];
      R[k][i] = ld_temp;
    }

    offset = new Vector<T>(A.capacity());
    orthogonalized = new Vector<T>(A.capacity());
    temp = new Vector<T>(A.capacity());

    for(unsigned long j = 0; j < k; j++)
    {
      *temp = (R[k][j] * Q[j]);
      *offset = *offset + *temp;
    }

    *orthogonalized = A[k] - (*offset);

    ld_temp = n2(*orthogonalized, 2);
    R[k][k] = ld_temp;
    cout << *orthogonalized;
    constant = 1.0/(R[k][k]);
    Q[k] = (constant * (*orthogonalized));
    cout << "====k:" << k << "=====" << endl;
    cout << Q[k];

    delete offset;
    delete orthogonalized;
    delete temp;
  }
}

#endif //QRDECOMP_HPP
