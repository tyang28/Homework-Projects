 /** functions.cpp
 *Teng-Ju Yang 
 *tyang28  
 */

#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>
#include "functions.h"

using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;



int dioccur (string digraph, std::ifstream& FILE2) {
  string word;
  string input;
  int count = 0;
  getline(FILE2, input);
  
  for(unsigned int a = 0; a < digraph.length(); a++) {
    digraph[a] = tolower(digraph[a]);
  }
  
  while(FILE2 >> word) {
    for(unsigned int i = 0; i < word.length(); i++) {
      word[i] = tolower(word[i]);
    }
    
    if(word.find(digraph) != string::npos) {
      count++;
      
    }
    
  }
  
  FILE2.close();  
  return count;
}
void printString (string digraph, std::ifstream& FILE3) {
  string word;
  string input;
  getline(FILE3, input);

  for(unsigned int a = 0; a < digraph.length(); a++) {
    digraph[a] = tolower(digraph[a]);
  }
  
  while(FILE3 >> word) {
    for(unsigned int i = 0; i < word.length(); i++) {
      word[i] = tolower(word[i]);
    }
    
    if(word.find(digraph) != string::npos) {
      cout << word << ", "; 
    }

  }

  FILE3.close();

}

int numprintString (string digraph, std::ifstream& FILE3) {
  string word;
  string input;
  int check = 1;
  getline(FILE3, input);
  
  for(unsigned int a = 0; a < digraph.length(); a++) {
    digraph[a] = tolower(digraph[a]);
  }
  
  while(FILE3 >> word) {
    for(unsigned int i = 0; i < word.length(); i++) {
      word[i] = tolower(word[i]);
    }

    if(word.find(digraph) != string::npos) {
      cout << word << endl;
      check = 2;
    }

  }

  FILE3.close();
  return check;
}

void normalprintString (string digraph, std::ifstream& FILE2) {
  string word;
  string input;
  getline(FILE2, input);

  for(unsigned int a = 0; a < digraph.length(); a++) {
    digraph[a] = tolower(digraph[a]);
  }
  
  while(FILE2 >> word) {
    for(unsigned int i = 0; i < word.length(); i++) {
      word[i] = tolower(word[i]);
    }
    
    if(word.find(digraph) != string::npos) {
      cout << word << endl;
    }

  }

  FILE2.close();
}


