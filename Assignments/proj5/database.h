#ifndef _DATABASE_H
#define _DATABASE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <omp.h>
#include <tr1/unordered_set>

#include "cputime.h"
#include "play.h"
#include "parse.h"

using namespace std;
using namespace tr1;



struct sortPlayFunc {
  inline bool operator() (Play* play1, Play* play2) {
    return (play1->getRelevance() > play2->getRelevance());
  }
};

struct sortTime {
  inline bool operator() (double i, double j) {
    return (i > j);
  }
};

class Database {
  private:
    int stoi (string s);
 
  public:
    vector<Play*> temp_data;
    vector<Play*> data;
    unordered_set<Play*, Play::Hash> hashedData;
    vector<Play*> rel_data;
    vector<Play*> rel_hashed;
    vector<double> vTime;
    vector<double> hTime;
    double vSTime;
    double vMin;
    double vMax;
    double vMean;
    double hSTime;
    double hMin;
    double hMax;
    double hMean;

    Database();
    void addData (vector<Play*>);
    void analyze (vector<string> &);
    void print (vector<string>);
    void moveData ();
    void moveRelData (vector<string>);
    void prtVec (vector<string>);
    void prtHash (vector<string>);
    void calcTime ();
};

#endif
