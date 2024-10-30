#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Pirate.h"
using namespace std;
enum Choices {TRANSLATE = 1, ADD, QUIT};
int menu();
void addWord();
void translate();

int main() {
  int choice;
  do{
    choice = menu();
    switch(choice){
      case TRANSLATE:
        translate();
        break;
      case ADD:
        addWord();
        break;   
    }
  }while(choice != QUIT);
}

int menu(){
  int choice; 
  cout << "Ahoy Mates, Ye be choozen yer menu\n";
  cout << "1.  Translate\n2.  Add to Dictionary\n3.  Quit\n";
  cin >> choice;
  cin.ignore();
  return choice;
}


void translate(){
  Pirate p;
  string sentence, pirate;
  cout << "\nEnter yer words: " ;
  getline(cin, sentence);
  //cout << "SENTENCE: " << sentence << endl;
  pirate = p.translateSentence(sentence);
  cout << endl << "Here it be in pirate speak: " << pirate << endl << endl;
}


void addWord(){
   Pirate p;
   string english, pirate;
   cout << "Enter an English word: ";
   getline(cin, english);
   
   cout << "\nEnter the Pirate translation: " << endl;
   getline(cin, pirate);
   p.addToFile(english, pirate);
 
}
