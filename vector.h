//////////////////////////////////////////////////////////////////////
/// @file vector.h
/// @author Connor McBride
/// @brief Contains the declaration information for the Vector class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class Vector
/// @brief Is a template class that is a container.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<T>::Vector()
/// @brief Explicit definition of the default constructor.
/// @pre None
/// @post A Vector class of type T is created with m_size 0
/// @return Returns Vector object instantiated
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<T>::Vector(unsigned long size)
/// @brief Overload of constructor which takes an int for size
/// @pre None
/// @post A Vector class of type T is created with m_size size
/// @return Returns Vector object instantiated
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<T>::~Vector()
/// @brief Overload of the destructor
/// @pre None.
/// @post All m_elements of the calling object are cleared.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn unsigned long Term<T>::size() const
/// @brief Get function for m_size.
/// @pre None.
/// @post Returns size of vector.
/// @return Returns m_size of the called object.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn unsigned long Term<T>::capacity() const
/// @brief Get function for m_capacity.
/// @pre None.
/// @post Returns capacity of vector.
/// @return Returns m_capacity of the called object.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn T Vector<T>::operator [](int index) const
/// @brief Returns a returns element at passed index.
/// @pre Index needs to be less than the number of elements.
/// @post Returns a returns element at passed index.
/// @param1 Index of the term to be returned.
/// @return Returns a returns element at passed index.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend Vector<T> operator +(const Vector<T>& lhs, const Vector<T>& rhs)
/// @brief Adds two Vectors together.
/// @pre Vectors need to be of the same size. T type must have += operator.
/// @post Returns sum of lhs and rhs
/// @param1 Vector 1 to be added
/// @param2 Vector 2 to be added
/// @return Sum of lhs and rhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend Vector<T> operator -(const Vector<T>& lhs, const Vector<T>& rhs)
/// @brief Subtracts rhs vector from lhs.
/// @pre Vectors need to be of the same size. T type must have -= operator.
/// @post Returns difference of lhs and rhs
/// @param1 Vector 1 to be subracted from
/// @param2 Vector 2 to be subracted
/// @return Difference of lhs and rhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend T operator *(const Vector<T>& lhs, const Vector<T>& rhs)
/// @brief Dot product of rhs and lhs.
/// @pre T needs to have += operator and * operator.
/// @post Return dot product of rhs & lhs.
/// @param1 Vector 1
/// @param2 Vector 2
/// @return Dot of rhs from lhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend Vector<T> operator *(double c, const Vector<T>& rhs)
/// @brief Multiplication c by each element of rhs.
/// @pre T type must have *= operator.
/// @post Returns rhs with each element multiplied by c
/// @param1 constant c to be multiplied
/// @param2 Vector to be scaled
/// @return Rhs with each element multiplied by c
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn ostream& operator <<(ostream& out, const Vector<T>& rhs)
/// @brief Outputs rhs to ostream.
/// @pre None.
/// @post ostream is appended with information on rhs.
/// @param1 ostream operator to be changed.
/// @param2 Vector whose info is to be output.
/// @return ostream& with debug string for vector information added to the stream.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn istream& operator <<(istream& in, Vector<T>& rhs)
/// @brief Takes in istream and fills vector.
/// @pre None.
/// @post Rhs is filled with appropriate information. istream in gets returned.
/// @param1 istream operator to be returned.
/// @param2 Vector whose info is to be input.
/// @return istream& in.
//////////////////////////////////////////////////////////////////////

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

// Forward declarations for friend functions
template <typename T>
class Vector;

template <typename T>
Vector<T> operator +(const Vector<T>& lhs, const Vector<T>& rhs);

template <typename T>
Vector<T> operator -(const Vector<T>& lhs, const Vector<T>& rhs);

template <typename T>
T operator *(const Vector<T>& lhs, const Vector<T>& rhs);

template <typename T>
Vector<T> operator *(double c, const Vector<T>& rhs);

template <typename T>
ostream& operator <<(ostream& out, const Vector<T>& rhs);

template <typename T>
istream& operator >>(istream& in, Vector<T>& rhs);

template <typename T>
class Vector
{
public:
  // Constructor/Destructors
  Vector();
  Vector(const Vector<T>& other);
  Vector(unsigned long size);
  ~Vector();

  // Getters
  unsigned long size() const;
  unsigned long capacity() const;

  // Operators
  Vector<T>& operator =(const Vector<T>& other);
  T operator [](int index) const;
  T& operator [](int index);
  friend Vector<T> operator + <>(const Vector<T>& lhs, const Vector<T>& rhs);
  friend Vector<T> operator - <>(const Vector<T>& lhs, const Vector<T>& rhs);
  friend T operator * <>(const Vector<T>& lhs, const Vector<T>& rhs);
  friend Vector<T> operator * <>(double c, const Vector<T>& rhs);
  friend ostream& operator << <>(ostream& out, const Vector& rhs);
  friend istream& operator >> <>(istream& in, Vector& rhs);

private:
  unsigned long m_size;
  unsigned long m_capacity;
  T * m_elements;
};

#include "vector.hpp"

#endif //VECTOR_H
