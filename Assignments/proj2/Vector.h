#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>

using namespace std;

template<class T>
class Vector {
  public:
    // Member Functions
    Vector ();
    ~Vector ();
    void push_back (const T &);
    void pop_back ();
    T& operator[] (int);
    int size () const;
    void clear ();

  private:
    // Private Data
    int _size;
    int capacity;
    T * buffer;
};

template<class T>
Vector<T>::Vector () {
  _size = 0;
  capacity = 2;
  buffer = new T[capacity];
}

template<class T>
Vector<T>::~Vector () {
  delete[] buffer;
}

template<class T>
void Vector<T>::clear () {
  _size = 0;
  capacity = 2;
}

template<class T>
void Vector<T>::push_back (const T &val) {
  if (_size >= capacity)
    capacity *= 4;
    T *tempBuffer = new T[capacity];
    
    for (int i = 0; i < _size; ++i)
      tempBuffer[i] = buffer[i];
    
    delete[] buffer;
    buffer = tempBuffer;
    buffer[_size++] = val;
}

template<class T>
void Vector<T>::pop_back () {
  _size--;
}

template<class T>
T& Vector<T>::operator[] (int idx) {
  return buffer[idx];
}

template<class T>
int Vector<T>::size () const {
  return _size;
}

#endif
