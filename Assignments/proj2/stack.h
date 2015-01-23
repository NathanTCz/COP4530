#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include "Vector.h"

using namespace std;

template<class T>
class stack {
  private:
    // Private Data
    Vector<T> stk;
  
    // Private Helper Functions
  
  public:
    void push (T &);
    void pop ();
    T &top ();
    bool empty ();
    T &at (int);
};

template<class T>
void stack<T>::push (T &val) {
  stk.push_back(val);
}

template<class T>
void stack<T>::pop () {
  stk.pop_back();
}

template<class T>
T& stack<T>::top () {
  if (!empty())
    return stk[(stk.size() - 1)];
  else
    return 0;
}

template<class T>
bool stack<T>::empty () {
  if (stk.size() == 0)
    return true;
  else if (stk.size() > 0)
    return false;
}

template<class T>
T& stack<T>::at (int i) {
  return stk[i];
} 

#endif
