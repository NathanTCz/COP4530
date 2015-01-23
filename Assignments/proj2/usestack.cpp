#include <iostream>
#include "stack.h"

using namespace std;

int main (int argc, char * argv[]) {
  stack<int> stk;

  int a = 1;
  int b = 2;
  int c = 3;

  stk.push(a);
  stk.push(b);
  stk.push(c);
  stk.pop();

  if (stk.at(0) == 1) {
    if (stk.at(1) == 2) {
      cout << "Stack works" << endl;
    }
  }
  else cout << "Stack does not work" << endl;
  
  return 0;
}
