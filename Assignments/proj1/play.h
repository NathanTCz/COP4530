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
    float relevance;
	
    // Helper functions
    void search ();
    int stoi (string);
	
  public:
    Play (string, string, string, string, string, string, string, string);
    Play (Play *);
    bool list (string, string, string, string, string, string, string);
    bool summary (string, string, string, string);
    void setRelevance (string, string, string, string, string, string);
    float getRelevance();
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
};

#endif
