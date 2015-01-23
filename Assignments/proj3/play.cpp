#include "play.h"

Play::Play (string quar, string mins, string off, string def, string dwn, string yds, string onYd, string desc) {
  quarter = stoi(quar);
  minsRemain = stoi(mins);
  offense = off;
  defence = def;
  down = stoi(dwn);
  ytg = stoi(yds);
  onYdln = stoi(onYd);
  playDesc = desc;
  type = "unknown";
  relevance = 0;
  hits = 0;
  valid = true;

  this->search();
  if (type == "unknown") valid = false;
}

Play::Play (Play &newObj) {
  quarter = newObj.getQuarter();
  minsRemain = newObj.getMins();
  offense = newObj.getOffense();
  defence = newObj.getDefence();
  down = newObj.getDown();
  ytg = newObj.getYtg();
  onYdln = newObj.getOnYdln();
  playDesc = newObj.getPlayDesc();
  type = newObj.getType();
  relevance = newObj.getRelevance();
}

bool Play::list (string n, string min, string off, string def, string dwn, string togo, string ydline) {
}

bool Play::summary (string off, string dwn, string togo, string ydline) {
  int currDwn = stoi(dwn);
  int ydsTogo = stoi(togo);
  int ydLn = stoi(ydline);

  if (offense == off && down == currDwn) {
    if ((ydsTogo + 1) == ytg || (ydsTogo - 1) == ytg || ydsTogo == ytg) {
      if (onYdln >= (((double)ydLn *.10) - (double)ydLn) || onYdln <= (((double)ydLn * .10) + (double)ydLn)) {
        return true;
      }
    }
  }
  else return false;
}

void Play::search () {
  if (playDesc.find("deep") != string::npos) {
    if (playDesc.find("pass") != string::npos) {
      if (playDesc.find("right") != string::npos) {
        type = "dpr";
        playSummary = "deep pass right";
      }
    }
  }
  if (playDesc.find("deep") != string::npos) {
    if (playDesc.find("pass") != string::npos) {
      if (playDesc.find("left") != string::npos) {
        type = "dpl";
        playSummary = "deep pass left";
      }
    }
  }
  if (playDesc.find("deep") != string::npos) {
    if (playDesc.find("pass") != string::npos) {
      if (playDesc.find("middle") != string::npos) {
        type = "dpm";
        playSummary = "deep pass middle";
      }
    }
  }
  if (playDesc.find("short") != string::npos) {
    if (playDesc.find("pass") != string::npos) {
      if (playDesc.find("right") != string::npos) {
        type = "spr";
        playSummary = "short pass right";
      }
    }
  }
  if (playDesc.find("short") != string::npos) {
    if (playDesc.find("pass") != string::npos) {
      if (playDesc.find("left") != string::npos) {
        type = "spl";
        playSummary = "short pass left";
      }
    }
  }
  if (playDesc.find("short") != string::npos) {
    if (playDesc.find("pass") != string::npos) {
      if (playDesc.find("middle") != string::npos) {
        type = "spm";
        playSummary = "short pass middle";
      }
    }
  }
  if (playDesc.find("pass") == string::npos) {
    if (playDesc.find("right") != string::npos) {
      type = "rr";
        playSummary = "run right";
    }
  }
  if (playDesc.find("pass") == string::npos) {
    if (playDesc.find("left") != string::npos) {
      type = "rl";
        playSummary = "run left";
    }
  }
  if (playDesc.find("pass") == string::npos) {
    if (playDesc.find("middle") != string::npos) {
      type = "rm";
        playSummary = "run middle";
    }
  }
  if (playDesc.find("field") != string::npos) {
    if (playDesc.find("goal") != string::npos) {
      type = "fg";
        playSummary = "field goal attempt";
    }
  }
  if (playDesc.find("punts") != string::npos) {
    type = "pnt";
        playSummary = "punt";
  }
}

void Play::setRelevance(string min, string off, string def, string dwn, string togo, string ydline) {
  int currDwn = stoi(dwn);
  int ydsTogo = stoi(togo);
  int ydLn = stoi(ydline);
  int Min = stoi(min);

  relevance = -(abs((double)Min-(double)minsRemain)*5/3 + abs((double)ydsTogo-(double)ytg) + abs((double)ydLn-(double)onYdln));

  if (def == defence)
    relevance += 100; 
}

double Play::getRelevance() {
  return relevance;
}

int Play::getQuarter () {
  return quarter;
}

int Play::getMins () {
  return minsRemain;
}

string Play::getOffense () {
  return offense;
}

string Play::getDefence () {
  return defence;
}

int Play::getDown () {
  return down;
}

int Play::getYtg () {
  return ytg;
}

int Play::getOnYdln () {
  return onYdln;
}

string Play::getPlayDesc () {
  return playDesc;
}

string Play::getType () {
  return type;
}

string Play::getSummary () {
  return playSummary;
}

void Play::__hit__ () {
  hits++;
}

int Play::getHits () {
  return hits;
}

bool Play::_valid() {
  return valid;
}

int Play::stoi (string s) {
  int temp = 0;

  istringstream is(s);
  is >> temp;
  
  return temp;
}
