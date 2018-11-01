/**
1;95;0c *HW5 
 *Teng-Ju Yang tyang28
 */

#include <iostream>
#include <sstream>
//#include <cstdio>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include "functions.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;
typedef map<string, int> Map;

int main(int argc, char* argv[]) {
  if(argc != 3) {
    cout << "Failed to provide correct number of arguments" << endl;
    return 1;
  }
  std::ifstream FILE;
  std::ifstream FILE2;
  
  FILE.open(argv[1], std::ifstream::in);
  string arg2 = argv[2];
  int num;
  string input;
  int ninput;
  int count = 0;
  string digraph;
  string digraphline;
  FILE >> num;
  //getline(FILE, digraphline);
  //cout << digraphline << endl;
  std::set<string> sorted;
  while(count < num) {
    FILE >> digraph;
    count++;
    sorted.insert(digraph);
  }
  if(arg2 == "a") {
    for(std::set<string>::iterator it = sorted.begin(); it != sorted.end(); it++) {
      FILE2.open(argv[1], std::ifstream::in);
      cout << *it << ": [";    
      int ndioccur = dioccur(*it, FILE2);
      cout << "]" << endl;      
    }
    
  }
  
  else if (arg2 == "r"){
    for(std::set<string>::reverse_iterator it = sorted.rbegin(); it != sorted.rend(); it++) {
      FILE2.open(argv[1], std::ifstream::in);
      cout << *it << ": [";
      int ndioccur = dioccur(*it, FILE2);
      cout << "]" << endl;
    }
  }
  /*
  else if (arg2 == "c"){
    cout << "cr" << endl;
  }
  */
  
  cout << "q?>";
  string qquit = "quit";
  cin >> input;
  if(isdigit(input[0])) {
    cout << "int" << endl;
  }
  else if(input.compare(qquit) == 0) {
    cout << "str" << endl;
  }
  else if(isalpha(input[0])) {
    cout << "str" << endl;
    return 1;
  }
  
  return 0;
}
