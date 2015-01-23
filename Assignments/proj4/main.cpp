/*--------__----------*/
/*-------|  |---------*/
/*-------|  |---------*/
/*-------|  |---------*/
/*-______|  |___------*/
/*/  |  |    |  |--__-*/ 
/*|  |  |    |  |-/  |*/
/*|              /  /-*/ 
/*|                /--*/ 
/*\_______________/---*/

#include <iostream>
#include <vector>
#include <omp.h>
#include "parse.h"
#include "database.h"

using namespace std;

int main (int argc, char* argv[]) {
  Database * dataSet = new Database;
  
  if (argc >=2) {
    cout << "Processing " << flush;

//    #pragma omp parallel for schedule(dynamic)
    for (int i = 1; i <= (argc-1); i++) {
      Parse dataFile(argv[i]);
      dataFile.parseFile(dataSet);
    
      //dataSet->addData(dataFile.playBook);
    }
    
    string temp;
    vector<string> cmd;

    do {
      // Blank cmd vector
      cmd.clear();
      

      cout << endl;
      cout << "> ";
      
      getline(cin, temp);
      istringstream iss(temp);
      
      while (getline(iss, temp, ' ')) {
        cmd.push_back(temp);
      }
      
      if (cmd.front() == "summary") {
        //cout << "summary is the command" << endl;
        dataSet->analyze(cmd);
      }    
      else if (cmd.front() == "list") {
        //cout << "list is the command" << endl;
        dataSet->analyze(cmd);
      }
      else if (cmd.front() == "print") {
        dataSet->analyze(cmd);
      }
      else if (cmd.front() == "help") {
        cout << endl;
        cout << "--- USAGE ---" << endl;
        cout << "summary OFF DOWN TOGO YDLINE" << endl;
        cout << "list n MIN OFF DEF DOWN TOGO YDLINE" << endl;
        cout << "help - show this dialog." << endl;
        cout << endl;
        cout << "x - exit" << endl;
      }
      else if (cmd.front() == "x");
      else cout << "Invalid command" << endl;
      
    }
    while (cmd.front() != "x");
  }
  else cout << "Please enter a year or sequence of years." << endl;
}
