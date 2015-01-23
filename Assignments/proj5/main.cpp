#include <iostream>
#include <vector>
#include <omp.h>

#include "cputime.h"
#include "parse.h"
#include "database.h"

using namespace std;

double START_TIME;
double END_TIME;

int main (int argc, char* argv[]) {
  Database * dataSet = new Database;
  
  if (argc >=2) {
    #pragma omp parallel for schedule(dynamic)
    for (int i = 1; i <= (argc-1); i++) {
      Parse dataFile(argv[i]);
      dataFile.parseFile();
    
      dataSet->addData(dataFile.playBook);
    }

    dataSet->moveData();

    string temp;
    vector<string> cmd;

    do {
      // Blank cmd vector
      cmd.clear();
      
      getline(cin, temp);
      istringstream iss(temp);
      
      while (getline(iss, temp, ' ')) {
        cmd.push_back(temp);
      }
      
      if (cmd.front() == "list") {
        //cout << "list is the command" << endl;
        dataSet->analyze(cmd);
      }

      else if (cmd.front() == "x")
        dataSet->calcTime();

      else cout << "Invalid command" << endl;
      
    }
    while (cmd.front() != "x");
  }
  else cout << "Please enter a year or sequence of years." << endl;
}
