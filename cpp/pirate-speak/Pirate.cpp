#include "Pirate.h"

string Pirate::translateWord(string word) {
  std::ifstream filein("./pirate.csv", std::ios::in);
  string english, pirate;

  while(!filein.eof()) {
    getline(filein, english, ',');
    getline(filein, pirate, '\n');

    if (english == word) {
      filein.close();
      return pirate;
    }
  }

  filein.close();
  return word;
}

string Pirate::translateSentence(string input) {
  std::stringstream sentenceReader(input);
  string pirateSentence = "";

  while(sentenceReader.good()) {
    string temp;
    getline(sentenceReader, temp, ' ');
    pirateSentence += translateWord(temp) + " ";
  }

  return pirateSentence;
}

void Pirate::addToFile(string english, string pirate) {
  std::ofstream fileout("./pirate.csv", std::ios::app);
  fileout << std::endl << english << ", " << pirate;
  fileout.close();
}
