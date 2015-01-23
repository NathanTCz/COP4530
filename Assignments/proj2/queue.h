#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include "Vector.h"

using namespace std;

template<class T>
class queue {
  private:
  // Private Data
  Vector<T> kew;
  
  // Private Helper Functions
  
  public:
    void push (T &);
    void pop ();
    T& front ();
    bool empty ();
};

template<class T>
void queue<T>::push (T &val) {
  int newSize = (kew.size() + 1);
  T *tempKew = new T[newSize];

  tempKew[0] = val;

  for (int i = 0; i < kew.size(); ++i)
    tempKew[i + 1] = kew[i];
  
  kew.clear();

  for (int i = 0; i < newSize; ++i)
    kew.push_back(tempKew[i]);

  delete[] tempKew;
}

template<class T>
void queue<T>::pop () {
  kew.pop_back();
}

template<class T>
T& queue<T>::front () {
  if (!empty())
    return kew[ (kew.size() - 1) ];
  else
    return 0;
}

template<class T>
bool queue<T>::empty () {
  if (kew.size() == 0)
    return true;
  else if (kew.size() > 0)
    return false;
}

#endif
