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

using std::cout;
using std::endl;
using std::string;
using std::map;
typedef map<string, int> Map; 


int dioccur (string digraph, std::ifstream& FILE2) {
  string word;
  string input;
  int count = 0;
  getline(FILE2, input);
  //getline(FILE2, input);
  for(unsigned int a = 0; a < digraph.length(); a++) {
    digraph[a] = tolower(digraph[a]);
  }
  for(unsigned int i = 0; i < word.length(); i++) {
      word[i] = tolower(word[i]);
  }
  
  while(FILE2 >> word) {
    
    if(word.find(digraph) != string::npos) {
      count++;
    }   
  }
  FILE2.close();  
  return count;
}

/*
void Mapmake(Map mappedword, string digraph) {
  string input;
  
}
*/
