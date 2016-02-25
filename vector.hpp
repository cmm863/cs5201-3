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
  this->m_capacity = 0;
  this->m_size = 0;
  this->m_elements = nullptr;
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other)
{
  this->m_capacity = other.m_capacity;
  this->m_size = other.m_size;
  this->m_elements = new (nothrow) T[this->m_capacity];
  for(int i = 0; i < this->m_size; i++)
  {
    this->m_elements[i] = other.m_elements[i];
  }
}

template <typename T>
Vector<T>::Vector(unsigned long size)
{
  this->m_capacity = size;
  this->m_size = 0;
  this->m_elements = new (nothrow) T[this->m_capacity];
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
unsigned long Vector<T>::capacity() const
{
  return this->m_capacity;
}

template <typename T>
T Vector<T>::operator [](int index) const
{
  if(this->m_size <= index)
  {
    cerr << "Out of bounds on [] operator." << endl;
  }

  return this->m_elements[index];
}

template <typename T>
Vector<T> operator +(const Vector<T>& lhs, const Vector<T>& rhs)
{
  if(lhs.m_size != rhs.m_size)
  {
    cerr << "Sizes not equal for + operator." << endl;
  }
  Vector<T> ret(lhs);
  for(unsigned long i = 0; i < ret.m_size; i++)
  {
    ret.m_elements[i] += rhs.m_elements[i];
  }

  return ret;
}

template <typename T>
Vector<T> operator -(const Vector<T>& lhs, const Vector<T>& rhs)
{
  if(lhs.m_size != rhs.m_size)
  {
    cerr << "Sizes not equal for - operator." << endl;
  }
  Vector<T> ret(lhs);
  for(unsigned long i = 0; i < ret.m_size; i++)
  {
    ret.m_elements[i] -= rhs.m_elements[i];
  }

  return ret;
}

template <typename T>
Vector<T> operator *(double c, const Vector<T>& rhs)
{
  Vector<T> ret(rhs);
  for(unsigned long i = 0; i < ret.m_size; i++)
  {
    ret.m_elements[i] *= c;
  }

  return ret;
}


template <typename T>
ostream& operator <<(ostream& out, const Vector<T> &rhs)
{
  for(unsigned long i = 0; i < rhs.m_size; i++)
  {
    out << rhs.m_elements[i] << " ";
  }

  return out;
}

template <typename T>
istream& operator >>(istream& in, Vector<T> &rhs)
{
  string element;
  for(unsigned long i = 0; i < rhs.m_capacity; i++)
  {
    in >> element;
    rhs.m_elements[i] = atoi(element.c_str());
    rhs.m_size++;
  }
  return in;
}

#endif //VECTOR_HPP
