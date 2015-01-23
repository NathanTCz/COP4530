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

void Parse::explode (string & s, char delim, string out[13]) {
  istringstream stream(s);
  string temp;
  int iterator = 0;
  
  while (getline(stream, temp, delim)) {
      out[iterator++] = temp;
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
  string exploded[13];
  explode(item, ',', exploded);

	Play *tempPlayObj = new Play (exploded[1],
	                              exploded[2],
				      exploded[4],
				      exploded[5],
                                      exploded[6],
                                      exploded[7],
                                      exploded[8],
                                      exploded[9]
                                     );
					 
  playBook.push_back(tempPlayObj);
  getline(fileObj, item); 
  }
}
