#include "database.h"

struct compareObjAtt {
  inline bool operator() (Play* play1, Play* play2) {
    return (play1->getRelevance() > play2->getRelevance());
  }
};

void Database::addData (vector <Play*> playBook) {
  data.push_back(playBook);
}

void Database::analyze (vector<string> &cmd) {
  int totalSim = 0;
  double dpr, dpl, dpm, spr, spl, spm, rr, rl, rm, fg, pnt = 0.0;
  vector<Play*> relPlays;

  for (vector< vector <Play*> >::iterator vec = data.begin(); vec != data.end(); vec++) {
    for (vector<Play*>::iterator i = (*vec).begin(); i != (*vec).end(); i++) {
      if ((cmd).front() == "summary") {
        bool similar = (*i)->summary(cmd.at(1),
                                     cmd.at(2),
                                     cmd.at(3),
                                     cmd.at(4)
                                    );
        if (similar) {
          // Was having trouble using ++ operator
          totalSim++;
          increment((*i)->getType(), dpr, dpl, dpm, spr, spl, spm, rr, rl, rm, fg, pnt);
        }
      }
      if ((cmd).front() == "list") {
        (*i)->setRelevance(cmd.at(2),
                           cmd.at(3),
                           cmd.at(4),
                           cmd.at(5),
                           cmd.at(6),
                           cmd.at(7)
                          );
      }
    }
    if (cmd.front() == "list") {
      sort((*vec).begin(), (*vec).end(), compareObjAtt());
      relPlays = getNRelevant((*vec), stoi(cmd.at(1)));
    }
  }
  print(cmd.front(), relPlays, totalSim, dpr, dpl, dpm, spr, spl, spm, rr, rl, rm, fg, pnt);
}

vector<Play*> Database::getNRelevant (vector<Play*> vec, int n) {
  vector<Play*> relPlays;
  for (int i = 0; i < n; i++) {
      relPlays.push_back(vec.at(i));
  }
  return relPlays;
}

void Database::increment (string type, double &dpr, double &dpl, double &dpm, double &spr, double &spl,
                          double &spm, double & rr, double &rl, double &rm, double &fg, double &pnt) 
{
  // Was having trouble using ++ operator
  if (type == "dpr") dpr += 1.0;
  if (type == "dpl") dpl += 1.0;
  if (type == "dpm") dpm += 1.0;
  if (type == "spr") spr += 1.0;
  if (type == "spl") spl += 1.0;
  if (type == "spm") spm += 1.0;
  if (type == "rr") rr += 1.0;
  if (type == "rl") rl += 1.0;
  if (type == "rm") rm += 1.0;
  if (type == "fg") fg += 1.0;
  if (type == "pnt") pnt += 1.0;
}

void Database::print (string command, vector<Play*> relPlays, int &totalSim, double &dpr, double &dpl, double &dpm, double &spr, double &spl,
                          double &spm, double & rr, double &rl, double &rm, double &fg, double &pnt)
{
    if (command == "summary") {
      if (totalSim == 0) cout << "No similar plays." << endl;
      else {
      dpr = ((dpr / (double)totalSim) * 100);
      dpl = ((dpl / (double)totalSim) * 100);
      dpm = ((dpm / (double)totalSim) * 100);
      spr = ((spr / (double)totalSim) * 100);
      spl = ((spl / (double)totalSim) * 100);
      spm = ((spm / (double)totalSim) * 100);
      rr = ((rr / (double)totalSim) * 100);
      rl = ((rl / (double)totalSim) * 100);
      rm = ((rm / (double)totalSim) * 100);
      fg = ((fg / (double)totalSim) * 100);
      pnt = ((pnt / (double)totalSim) * 100);
      
      cout << "Deep pass right: " << setprecision(5) << dpr << "%" << endl;
      cout << "Deep pass left: " << setprecision(5) <<  dpl << "%" << endl;
      cout << "Deep pass middle: " << setprecision(5) <<  dpm << "%" << endl;
      cout << "Short pass right: " << setprecision(5) <<  spr << "%" << endl;
      cout << "Short pass left: " << setprecision(5) <<  spl << "%" << endl;
      cout << "Short pass middle: " << setprecision(5) <<  spm << "%" << endl;
      cout << "Run to the right: " << setprecision(5) <<  rr << "%" << endl;
      cout << "Run to the left: " << setprecision(5) <<  rl << "%" << endl;
      cout << "Run to the middle: " << setprecision(5) <<  rm << "%" << endl;
      cout << "Field goal attempt: " << setprecision(5) <<  fg << "%" << endl;
      cout << "Punt: " << pnt << "%" << endl;
      }
    }
    else if (command == "list") {
      for (vector<Play*>::iterator it = relPlays.begin(); it != relPlays.end(); it++) {
        cout << (*it)->getSummary() << " "
             << (*it)->getMins() << " " 
             << (*it)->getOffense() << " "
             << (*it)->getDefence() << " "
             << (*it)->getDown() << " "
             << (*it)->getYtg() << " "
             << (*it)->getOnYdln() << endl;
      }
    }

}

int Database::stoi (string s) {
  int temp = 0;

  istringstream is(s);
  is >> temp;
  
  return temp;
}
