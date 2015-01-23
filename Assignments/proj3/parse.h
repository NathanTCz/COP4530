#ifndef _PARSE_H
#define _PARSE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "play.h"
#include "dll.h"

using namespace std;

class Parse {
  private:
    ifstream fileObj;

    // Helper Functions
    void explode(string & s, char delim, string array[13]);

  public:
    Dll<Play*> playBook;
    Parse (string);
    void parseFile ();


};

#endif
