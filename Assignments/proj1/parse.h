#ifndef _PARSE_H
#define _PARSE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>

#include "play.h"

using namespace std;

class Parse {
  private:
    string tmpTrash;
	  ifstream fileObj;

    // Helper Functions
    void explode(string & s, char delim, vector<string> &);

  public:
    vector<Play*> playBook;
    Parse (string);
    void parseFile ();


};

#endif
