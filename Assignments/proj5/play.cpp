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
  valid = true;
  _similar = false;
  hit = false;

  this->search();
  if (type == "unknown") valid = false;
}

bool Play::similar (string off, string dwn, string togo, string ydline) {
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
        playSummary = "Deep pass right";
      }
      else if (playDesc.find("left") != string::npos) {
        type = "dpl";
        playSummary = "Deep pass left";
      }
      else if (playDesc.find("middle") != string::npos) {
        type = "dpm";
        playSummary = "Deep pass middle";
      }
    }
  }
  else if (playDesc.find("short") != string::npos) {
    if (playDesc.find("pass") != string::npos) {
      if (playDesc.find("right") != string::npos) {
        type = "spr";
        playSummary = "Short pass right";
      }
      else if (playDesc.find("left") != string::npos) {
        type = "spl";
        playSummary = "Short pass left";
      }
      else if (playDesc.find("middle") != string::npos) {
        type = "spm";
        playSummary = "Short pass middle";
      }
    }
  }
  else if (playDesc.find("pass") == string::npos) {
    if (playDesc.find("right") != string::npos) {
      type = "rr";
        playSummary = "Run right";
    }
    else if (playDesc.find("left") != string::npos) {
      type = "rl";
        playSummary = "Run left";
    }
    else if (playDesc.find("middle") != string::npos) {
      type = "rm";
        playSummary = "Run middle";
    }
  }
  else if (playDesc.find("field") != string::npos) {
    if (playDesc.find("goal") != string::npos) {
      type = "fg";
        playSummary = "Field goal attempt";
    }
  }
  else if (playDesc.find("punts") != string::npos) {
    type = "pnt";
        playSummary = "Punt";
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

bool Play::_valid() {
  return valid;
}

void Play::setSimilar (bool x) {
  _similar = x;
}

bool Play::__similar () {
  return _similar;
}

void Play::_hit () {
  hit = true;
}

bool Play::been_hit () {
  return hit;
}

int Play::stoi (string s) {
  int temp = 0;

  istringstream is(s);
  is >> temp;
  
  return temp;
}
