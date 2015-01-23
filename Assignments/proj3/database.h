#ifndef _DATABASE_H
#define _DATABASE_H

#include <iostream>
#include "dll.h"
#include <iomanip>
#include <vector>
#include <algorithm>
#include "play.h"
#include "parse.h"

using namespace std;

class Database {
  private:

    Dll<Play*> getNRelevant (Dll<Play*>, vector<string>);
    int stoi (string s);
 
  public:
    Dll <Play*> data;
    void addData (Dll<Play*>);
    void analyze (vector<string> &);
    void reorganize (Dll<Play*>);
    void increment (string, double &, double &, double &, double &, double &,
                    double &,double &, double &, double &, double &, double &);
    void print (vector<string>, Dll<Play*>, double &, double &, double &, double &, double &, double &,
                    double &,double &, double &, double &, double &, double &);
};

#endif
