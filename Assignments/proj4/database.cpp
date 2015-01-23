#include "database.h"

void Database::addData (Play* play) {
  if ((play)->_valid())
    data.insert(play);
}

void Database::analyze (vector<string> &cmd) {
  double totalSim = 0.0;
  double dpr = 0.0;
  double dpl = 0.0;
  double dpm = 0.0;
  double spr = 0.0;
  double spl = 0.0;
  double spm = 0.0;
  double rr = 0.0;
  double rl = 0.0;
  double rm = 0.0;
  double fg = 0.0;
  double pnt = 0.0;

  Dll<Play*> relPlays;

  if ((cmd).front() == "summary") {
    data.summary(cmd, totalSim, dpr, dpl, dpm, spr, spl, spm, rr, rl, rm, fg, pnt);
  }

  if ((cmd).front() == "list") {
    data.get_relevant(relPlays, cmd);
    relPlays.sort();
    relPlays = getNRelevant(relPlays, cmd);

  }

  if ((cmd).front() == "print") {
    data.print(relPlays);
  }

  if (cmd.front() == "list") {
    for (Dll<Play*>::iterator rel = relPlays.begin(); rel != relPlays.end(); ++rel) {
      rel.hit();
    }

    //data.reorganize();
  }
  print(cmd, relPlays, totalSim, dpr, dpl, dpm, spr, spl, spm, rr, rl, rm, fg, pnt);
}

Dll<Play*> Database::getNRelevant (Dll<Play*> dll, vector<string> cmd) {
  Dll<Play*> relPlays;

  int counter = 0;

  for (Dll<Play*>::iterator itr = dll.begin(); counter != stoi(cmd.at(1)) && itr != dll.end(); ++itr) {
    bool similar = (*itr)->summary(cmd.at(3),
                                   cmd.at(5),
                                   cmd.at(6),
                                   cmd.at(7)
                                  );
    if (similar) {
      relPlays.push_back(*itr);
    }
    counter++;
  }

  return relPlays;
}

void Database::print (vector<string> cmd, Dll<Play*> relPlays, double &totalSim, double &dpr, double &dpl, double &dpm, double &spr, double &spl,
                          double &spm, double & rr, double &rl, double &rm, double &fg, double &pnt)
{
    if ((cmd).front() == "summary") {
      if (totalSim == 0) cout << "No similar plays." << endl;
      else {
        if (dpr != 0) 
          dpr = ((dpr / totalSim) * 100.00);
        if (dpl != 0) 
          dpl = ((dpl / totalSim) * 100.00);
        if (dpm != 0) 
          dpm = ((dpm / totalSim) * 100.00);
        if (spr != 0) 
          spr = ((spr / totalSim) * 100.00);
        if (spl != 0) 
          spl = ((spl / totalSim) * 100.00);
        if (spm != 0) 
          spm = ((spm / totalSim) * 100.00);
        if (rr != 0) 
          rr = ((rr / totalSim) * 100.00);
        if (rl != 0) 
          rl = ((rl / totalSim) * 100.00);
        if (rm != 0) 
          rm = ((rm / totalSim) * 100.00);
        if (fg != 0) 
          fg = ((fg / totalSim) * 100.00);
        if (pnt != 0) 
          pnt = ((pnt / totalSim) * 100.00);
      
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
    else if ((cmd).front() == "list") {
      for (Dll<Play*>::iterator it = relPlays.begin(); it != relPlays.end(); it++) {
        cout << (*it)->getSummary() << " "
             << (*it)->getMins() << " " 
             << (*it)->getOffense() << " "
             << (*it)->getDefence() << " "
             << (*it)->getDown() << " "
             << (*it)->getYtg() << " "
             << (*it)->getOnYdln() << " "
             << (*it)->getRelevance() << endl;
      }
    }
    else if ((cmd).front() == "print") {
      int cnt = 0;
      int n = stoi(cmd.at(1));

      for (Dll<Play*>::iterator it = relPlays.begin(); cnt < n && it != relPlays.end(); it++) {
        if ((*it)->_valid()) {
        cout << (*it)->getSummary() << " "
             << (*it)->getMins() << " " 
             << (*it)->getOffense() << " "
             << (*it)->getDefence() << " "
             << (*it)->getDown() << " "
             << (*it)->getYtg() << " "
             << (*it)->getOnYdln() << endl;

        cnt++;
      }
      }
    }

}

int Database::stoi (string s) {
  int temp = 0;

  istringstream is(s);
  is >> temp;
  
  return temp;
}
