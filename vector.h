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
/// @fn Vector<T>::Vector(int size)
/// @brief Overload of constructor which takes an int for size
/// @pre None
/// @post A Vector class of type T is created with m_size size
/// @return Returns Vector object instantiated
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn unsigned long Term<T>::size() const
/// @brief Get function for m_size.
/// @pre None.
/// @post Returns size of vector.
/// @return Returns m_size of the called object.
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
ostream& operator <<(ostream& out, const Vector<T>& rhs);

template <typename T>
istream& operator >>(istream& in, Vector<T>& rhs);

template <typename T>
class Vector
{
public:
  Vector();
  Vector(int size);
  ~Vector();
  unsigned long size() const;
  friend ostream& operator << <>(ostream& out, const Vector& rhs);
  friend istream& operator >> <>(istream& in, Vector& rhs);

private:
  unsigned long m_size;
  T * m_elements;
};

#include "vector.hpp"

#endif //VECTOR_H
