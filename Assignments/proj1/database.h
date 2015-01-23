#ifndef _DATABASE_H
#define _DATABASE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "play.h"
#include "parse.h"

using namespace std;

class Database {
  private:
    vector < vector<Play*> > data;

    vector<Play*> getNRelevant (vector<Play*>, int);
    int stoi (string s);
 
  public:
    void addData (vector<Play*>);
    void analyze (vector<string> &);
    void increment (string, double &, double &, double &, double &, double &,
                    double &,double &, double &, double &, double &, double &);
    void print (string, vector<Play*>, int &, double &, double &, double &, double &, double &,
                    double &,double &, double &, double &, double &, double &);
};

#endif
