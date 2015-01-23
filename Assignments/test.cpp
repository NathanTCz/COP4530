#include <iostream>
#include <vector>
#include <sstream>
#include <omp.h>

#include "cputime.h"
#include "parse.h"
#include "database.h"

double START_TIME;
double END_TIME;

int main (void) {
  Database * dataSet = new Database;


  #pragma omp parallel for schedule(dynamic)
  for (int i = 2007; i < 2013; ++i) {
    stringstream ss;
    ss << i;

    Parse dataFile(ss.str());
    dataFile.parseFile();
    dataSet->addData(dataFile.playBook);
  }

  dataSet->moveData();

  vector<string> cmd2;

  cmd2.push_back("list");
  cmd2.push_back("10");
  cmd2.push_back("46");
  cmd2.push_back("NYG");
  cmd2.push_back("DAL");
  cmd2.push_back("1");
  cmd2.push_back("10");
  cmd2.push_back("58");
 
  dataSet->analyze(cmd2);

  vector<string> cmd3;

  cmd3.push_back("list");
  cmd3.push_back("3");
  cmd3.push_back("47");
  cmd3.push_back("NYG");
  cmd3.push_back("DAL");
  cmd3.push_back("1");
  cmd3.push_back("10");
  cmd3.push_back("58");
  
  dataSet->analyze(cmd3);

  vector<string> cmd4;

  cmd4.push_back("list");
  cmd4.push_back("10");
  cmd4.push_back("46");
  cmd4.push_back("NYG");
  cmd4.push_back("DAL");
  cmd4.push_back("1");
  cmd4.push_back("10");
  cmd4.push_back("58");
  
  dataSet->analyze(cmd4);

//print times
  dataSet->calcTime();

  return 0;
}