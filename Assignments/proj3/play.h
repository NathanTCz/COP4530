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
    int hits;
    bool valid;
	
    // Helper functions
    void search ();
    int stoi (string);
	
  public:
    Play (string quar = "",
          string mins = "",
          string off = "",
          string def = "",
          string dwn = "",
          string yds = "",
          string onYd = "",
          string desc = ""
         );
    Play (Play &);
    bool list (string, string, string, string, string, string, string);
    bool summary (string, string, string, string);
    void setRelevance (string, string, string, string, string, string);
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
    void __hit__();
    int getHits();
    bool _valid();

};

#endif
