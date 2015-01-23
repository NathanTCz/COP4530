#ifndef _DATABASE_H
#define _DATABASE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "play.h"
#include "bst.h"
#include "dll.h"

using namespace std;

class Database {
  private:

    Dll <Play*> getNRelevant (Dll<Play*>, vector<string>);
    int stoi (string s);
 
  public:
    BST <Play*> data;
    void addData (Play*);
    void analyze (vector<string> &);
    void increment (string, double &, double &, double &, double &, double &,
                    double &,double &, double &, double &, double &, double &);
    void print (vector<string>, Dll<Play*>, double &, double &, double &, double &, double &, double &,
                    double &,double &, double &, double &, double &, double &);
};

#endif
