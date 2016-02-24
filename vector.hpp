//////////////////////////////////////////////////////////////////////
/// @file vector.hpp
/// @author Connor McBride
/// @brief Contains the Vector class implementation information
//////////////////////////////////////////////////////////////////////

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector.h"

template <typename T>
Vector<T>::Vector()
{
  this->m_size = 0;
  this->m_elements = nullptr;
}

template <typename T>
Vector<T>::Vector(int size)
{
  this->m_size = size;
  this->m_elements = new (nothrow) T[this->m_size];
}

template <typename T>
Vector<T>::~Vector()
{
  delete[] this->m_elements;
}

template <typename T>
unsigned long Vector<T>::size() const
{
  return this->m_size;
}

template <typename T>
ostream& operator <<(ostream& out, const Vector<T> &rhs)
{
  out << rhs.m_size;
  return out;
}

template <typename T>
istream& operator >>(istream& in, Vector<T> &rhs)
{
  string size;
  in >> size;
  rhs.m_size = atoi(size.c_str());
  return in;
}

#endif //VECTOR_HPP
