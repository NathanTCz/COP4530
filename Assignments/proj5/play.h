#ifndef _PLAY_H
#define _PLAY_H

#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Play {
  private:
    // Private Data
    int quarter;
    int minsRemain;
    string offense;
    string defence;
    int down;
    int ytg;
    int onYdln;
    string playDesc;
    string type;
    string playSummary;
    double relevance;
    bool valid;
    bool _similar;
    bool hit;
	
    // Helper functions
    void search ();
    int stoi (string);
	
  public:
    struct Hash {
        size_t operator()(Play* const &x) const {
          size_t t = 0;
          string u = x->getOffense();
          string v = x->getDefence();
          string w = x->getPlayDesc();

          t = u.length() + v.length() + w.length();

          return t;
        }
    };

    Play (string quar = "",
          string mins = "",
          string off = "",
          string def = "",
          string dwn = "",
          string yds = "",
          string onYd = "",
          string desc = ""
         );
    bool similar(string, string, string, string);
    void setRelevance(string, string, string, string, string, string);
    double getRelevance();
    int getQuarter();
    int getMins();
    string getOffense();
    string getDefence();
    int getDown();
    int getYtg();
    int getOnYdln();
    string getPlayDesc();
    string getType();
    string getSummary();
    bool _valid();
    void setSimilar(bool);
    bool __similar();
    void _hit();
    bool been_hit();

};

#endif
