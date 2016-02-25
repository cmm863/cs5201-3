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
/// @fn void Vector<T>::add(T e)
/// @brief Adds the element to the calling object.
/// @pre None.
/// @post The element passed is stored in the calling object.
/// @param1 The element to be added to the calling vector.
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

  // Helpers
  void add(const T& e);

  // Operators
  friend Vector<T> operator + <>(const Vector<T>& lhs, const Vector<T>& rhs);
  friend ostream& operator << <>(ostream& out, const Vector& rhs);
  friend istream& operator >> <>(istream& in, Vector& rhs);

private:
  unsigned long m_size;
  unsigned long m_capacity;
  T * m_elements;
};

#include "vector.hpp"

#endif //VECTOR_H