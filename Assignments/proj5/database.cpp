#include "database.h"

Database::Database () {
  vSTime = 0;
  hSTime = 0;
}

void Database::addData (vector<Play*> playBook) {
  for (vector<Play*>::iterator itr = playBook.begin(); itr != playBook.end(); ++itr) {
      temp_data.push_back(*itr);
  }
}

void Database::moveData () {
  #pragma omp parallel sections
  {
    double start = cputime();
    for (vector<Play*>::iterator itr = temp_data.begin(); itr != temp_data.end(); ++itr) {
      data.push_back(*itr);
    }
    vSTime = cputime() - start;

    #pragma omp section
    {
      double start = cputime();
      for (vector<Play*>::iterator itr = temp_data.begin(); itr != temp_data.end(); ++itr) {
        hashedData.insert(*itr);
      }
      hSTime = cputime() - start;
    }
  }
}

void Database::moveRelData (vector<string> cmd) {
  double start = cputime();
  for (vector<Play*>::iterator vec = data.begin(); vec != data.end(); ++vec) {
    if ( (*vec)->__similar() )
      rel_data.push_back( (*vec) );
  }
  double end = cputime();
  vTime.push_back(( end - start ));

  unordered_set<Play*>::iterator got;
  start = cputime();
  for (vector<Play*>::iterator vec = rel_data.begin(); vec != rel_data.end(); ++vec) {
    got = hashedData.find( (*vec) );

    if (got != hashedData.end())
      if ( (*got)->__similar() )
        rel_hashed.push_back(*got);
  }
  end = cputime();
  hTime.push_back(( end - start ));
}

void Database::analyze (vector<string> &cmd) {
  rel_data.clear();
  rel_hashed.clear();
#pragma omp parallel for schedule(dynamic, 5)
  for (int i = 0; i < data.size() - 1; ++i) {
  //for (vector<Play*>::iterator vec = data.begin(); vec != data.end(); ++vec) {
    //reset similar
    (data[i])->setSimilar(false);

    (data[i])->setRelevance(cmd.at(2),
                         cmd.at(3),
                         cmd.at(4),
                         cmd.at(5),
                         cmd.at(6),
                         cmd.at(7)
                        );

    if (
          (data[i])->similar(cmd.at(3),
                          cmd.at(5),
                          cmd.at(6),
                          cmd.at(7)
                         )
        )
    {
      (data[i])->setSimilar(true);
    } 
  }

  sort(data.begin(), data.end(), sortPlayFunc());
  //moveData();
  moveRelData(cmd);

  print(cmd);
}

void Database::print (vector<string> cmd) {
  prtVec(cmd);

  prtHash(cmd);
}

void Database::prtVec (vector<string> cmd) {
  int n = stoi(cmd.at(1));

  if (rel_data.size() < n) n = rel_data.size();

  for (int i = 0; i < n; ++i) {
    cout << (rel_data[i])->getSummary() << " "
         << (rel_data[i])->getMins() << " " 
         << (rel_data[i])->getOffense() << " "
         << (rel_data[i])->getDefence() << " "
         << (rel_data[i])->getDown() << " "
         << (rel_data[i])->getYtg() << " "
         << (rel_data[i])->getOnYdln() << " "
         << (rel_data[i])->getRelevance() << endl;
  }
  cout << endl;
}

void Database::prtHash (vector<string> cmd) {
  int n = stoi(cmd.at(1));

  if (rel_data.size() < n) n = rel_hashed.size();

    for (int i = 0; i < n; ++i) {
      cout << (rel_hashed[i])->getSummary() << " "
           << (rel_hashed[i])->getMins() << " " 
           << (rel_hashed[i])->getOffense() << " "
           << (rel_hashed[i])->getDefence() << " "
           << (rel_hashed[i])->getDown() << " "
           << (rel_hashed[i])->getYtg() << " "
           << (rel_hashed[i])->getOnYdln() << " "
           << (rel_hashed[i])->getRelevance() << endl;
    }
    cout << endl;
}

void Database::calcTime () {
  sort(vTime.begin(), vTime.end(), sortTime());
  sort(hTime.begin(), hTime.end(), sortTime());

  vMax = vTime.front();
  vMin = vTime.back();
  
  hMax = hTime.front();
  hMin = hTime.back();

  double sum = 0;
  for (vector<double>::iterator i = vTime.begin(); i != vTime.end(); ++i)
    sum += (*i);

  vMean = (sum / vTime.size());

  sum = 0;
  for (vector<double>::iterator i = hTime.begin(); i != hTime.end(); ++i)
    sum += (*i);

  hMean = (sum / vTime.size());

  cout << endl << endl;

  cout << setprecision(3) << "myhash: store " << hSTime << " s, list: min " << hMin
    << " s, max " << hMax << " s, mean "<< hMean << " s" << endl;

  cout << endl;

  cout << setprecision(3) << "mydatastructure: store " << vSTime << " s, list: min " << vMin
    << " s, max " << vMax << " s, mean "<< vMean << " s" << endl;
}

int Database::stoi (string s) {
  int temp = 0;

  istringstream is(s);
  is >> temp;
  
  return temp;
}
