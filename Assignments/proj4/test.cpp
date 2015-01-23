#include <iostream>
#include <vector>
#include <omp.h>
#include "parse.h"
#include "database.h"

int main (void) {
  Database * dataSet = new Database;

  Parse dataFile("2006");
  dataFile.parseFile(dataSet);

  vector<string> cmd;

  cmd.push_back("print");
  cmd.push_back("5");
  
  dataSet->analyze(cmd);


  vector<string> cmd1;

  cmd1.push_back("summary");
  cmd1.push_back("NYG");
  cmd1.push_back("1");
  cmd1.push_back("10");
  cmd1.push_back("84");

  dataSet->analyze(cmd1);


  vector<string> cmd2;

  cmd2.push_back("list");
  cmd2.push_back("1");
  cmd2.push_back("10");
  cmd2.push_back("NYG");
  cmd2.push_back("DAL");
  cmd2.push_back("2");
  cmd2.push_back("10");
  cmd2.push_back("84");
 
  dataSet->analyze(cmd2);

  vector<string> cmd3;

  cmd3.push_back("list");
  cmd3.push_back("1");
  cmd3.push_back("10");
  cmd3.push_back("NYG");
  cmd3.push_back("DAL");
  cmd3.push_back("2");
  cmd3.push_back("10");
  cmd3.push_back("84");
  
  dataSet->analyze(cmd3);


  vector<string> cmd4;

  cmd4.push_back("list");
  cmd4.push_back("1");
  cmd4.push_back("10");
  cmd4.push_back("NYG");
  cmd4.push_back("DAL");
  cmd4.push_back("2");
  cmd4.push_back("10");
  cmd4.push_back("84");
  
  if (cmd4.front() == "list") {
    //cout << "list is the command" << endl;
    dataSet->analyze(cmd4);
  }


  return 0;
}