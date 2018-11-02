/**
 *HW5 
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

using std::pair;
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;
//typedef multimap<int, string> Map;


int main(int argc, char* argv[]) {
  if(argc != 3) {
    cout << "Failed to provide correct number of arguments" << endl;
    return 1;
  }
  std::ifstream FILE;
  std::ifstream FILE2;
  std::ifstream FILE3;
  FILE.open(argv[1], std::ifstream::in);
  string arg2 = argv[2];
  int num;
  string input;
  int ninput;
  int count = 0;
  string digraph;
  string digraphline;
  FILE >> num;
  vector<string> sorted;
  std::multimap<int, string> mnew;
  //int cdioccur;
  //vector<Map> numsorted;
  while(count < num) {
    FILE >> digraph;
    count++;
    sorted.push_back(digraph);
  }
  sort(sorted.begin(), sorted.end());
  
  if(arg2 == "a") {
    for(vector<string>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
      string ignore;
      FILE3.open(argv[1], std::ifstream::in);
      cout << *it << ": [";
      printString(*it, FILE3);
      cout << "]" << endl;
      
    }
    
  }
  else if (arg2 == "r"){
    for(vector<string>::reverse_iterator it = sorted.rbegin(); it != sorted.rend(); ++it) {
      string ignore;
      FILE3.open(argv[1], std::ifstream::in);
      cout << *it << ": [";
      printString(*it, FILE3);
      cout << "]" << endl;
    }
  }
  else if (arg2 == "c") {
    for(vector<string>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
      FILE2.open(argv[1], std::ifstream::in);
      int a = dioccur(*it, FILE2);      
      mnew.insert(pair<int, string> (a, *it));      
    }
    
    for(std::multimap<int, string>::reverse_iterator it = mnew.rbegin(); it != mnew.rend(); ++it) {
      FILE3.open(argv[1], std::ifstream::in);
      cout << it->second << ": [";
      printString(it->second, FILE3);
      cout << "]" << endl;
    } 
  }  
  cout << "q?>";
  int check = 0;
  string qquit = "quit";
  cin >> input;
  if(isdigit(input[0])) {
    int inum = std::stoi(input);
    for(std::multimap<int, string>::iterator it = mnew.begin(); it != mnew.end(); ++it) {
      if(it->first == inum) {
	cout << it->second << endl;
	FILE3.open(argv[1], std::ifstream::in);
        numprintString(it->second, FILE3);
	check = 1;
      }
    }
    if(!check) {
      cout << "None" << endl;
    }
  }
  else if(input.compare(qquit) == 0) {
    return 1;
  }
  else if(isalpha(input[0])) {
    FILE2.open(argv[1], std::ifstream::in);
    int w = dioccur(input, FILE2);
    int check = 0;
    for(vector<string>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
      if(input.compare(*it) == 0) {
	cout << w << endl;
	FILE2.open(argv[1], std::ifstream::in);
	normalprintString(input, FILE2);
	check = 1;
      }
    }
    if(!check) {
      cout << "No such digraph" << endl;
    }    
  }
  return 0;
}
