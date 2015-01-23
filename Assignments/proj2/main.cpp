#include <iostream>
#include <stdlib.h>
#include <functional>
#include <string>
#include <sstream>

using namespace std;

int recurse (int);

class Recurse {
  private:
    int N1, C1, A1, M1, M2, M3, M4, D1, D2, S1, S2;
    char Op;
    
  public:
    Recurse(int, int, int, int, int, int, int, int, int, int, int, string);
    int f (int);
    
};

Recurse::Recurse(int n1, int c1, int a1, int m1, int m2, int m3, int m4, int d1, int d2, int s1, int s2, string OP) {
  istringstream iss(OP);

  N1 = n1;
  C1 = c1;
  A1 = a1;
  M1 = m1;
  M2 = m2;
  M3 = m3;
  M4 = m4;
  D1 = d1;
  D2 = d2;
  S1 = s1;
  S2 = s2;
  iss >> Op;
}

int Recurse::f (int Arg) {
  if (Arg < N1)
    return 0;
  else if (Arg == N1)
    return C1;
  else if (Arg > N1) {
    switch (Op) {
      case '+':
        return (A1 + M1*f(M2*Arg/D1 - S1) + M3*f(M4*Arg/D2 - S2));
        break;
      
      case '-':
        return (A1 + M1*f(M2*Arg/D1 - S1) - M3*f(M4*Arg/D2 - S2));
        break;
    }
  }
}

int main (int argc, char * argv[]) {
  int Arg = atoi(argv[12]);
  string Op = argv[13];
  
  Recurse obj(atoi(argv[1]),
              atoi(argv[2]),
              atoi(argv[3]), 
              atoi(argv[4]), 
              atoi(argv[5]), 
              atoi(argv[6]), 
              atoi(argv[7]), 
              atoi(argv[8]), 
              atoi(argv[9]), 
              atoi(argv[10]), 
              atoi(argv[11]),
              Op
              );
  
  cout << obj.f(Arg) << endl;

  return 0;
}

