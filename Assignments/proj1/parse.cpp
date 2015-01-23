#include "parse.h"

Parse::Parse (string file) {
  file.append(".csv");
  fileObj.open(file.c_str());
  
  if (fileObj.is_open()) cout << "." << flush;
  else {
    cout << "ERROR: Cannot find specified file. " << file << " does not exist." << endl;
    exit(EXIT_FAILURE);
  }
}

void Parse::explode (string & s, char delim, vector<string> &out) {
  istringstream stream(s);
  string temp;
  
  while (getline(stream, temp, delim)) {
      out.push_back(temp);
  }
}

void Parse::parseFile () {
  string item;
  string header;
  
  // Omit Header
  getline(fileObj, header);
  
  // Get the first line after header.
  getline(fileObj, item);
  
  while (!fileObj.eof()) {
  vector<string> exploded;
	explode(item, ',', exploded);
	
	Play *tempPlayObj = new Play (exploded.at(1),
	                              exploded.at(2),
				                        exploded.at(4),
				                        exploded.at(5),
                                exploded.at(6),
                                exploded.at(7),
                                exploded.at(8),
                                exploded.at(9)
                                );
					 
  playBook.push_back(tempPlayObj);	
  getline(fileObj, item); 
  }
}
