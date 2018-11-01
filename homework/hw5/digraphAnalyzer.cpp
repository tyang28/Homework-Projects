/**
 *HW5 
 *Teng-Ju Yang tyang28
 */

#include <iostream>
//#include <cstdio>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include "functions.h"

using std::cout;
using std::endl;
using std::string;
using std::map;
typedef map<string, int> Map;

int main(int argc, char* argv[]) {
  if(argc != 3) {
    cout << "Failed to provide correct number of arguments" << endl;
    return 1;
  }
  std::ifstream FILE;
  
  FILE.open(argv[1], std::ifstream::in);
  
  int num;
  int count = 0;
  string digraph;
  FILE >> num;
  
  while(count < num) {
    FILE >> digraph;
    dioccur(digraph, FILE);
    count++;
    break;
  }
  
  return 0;
}
