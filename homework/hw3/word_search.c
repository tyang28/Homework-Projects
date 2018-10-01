
// word_search.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
//
//

#include <stdlib.h>
#include <stdio.h>
#include "search_functions.h"
#include <string.h>
#include <ctype.h>

/*
 * This is the HW3 main function that performs a word search.
 */
int main(int argc, char* argv[]) {
  char str[MAX_SIZE];
  if(argc != 2) {
    printf("Please enter a command line argument\n");
    return 1;
  }
  /*
  char *grid[MAX_SIZE];

  for(int i = 0; i < MAX_SIZE; i++) {
    grid[i] = (char *)malloc(MAX_SIZE * sizeof(char)); 
  }
  */
  char grid[MAX_SIZE][MAX_SIZE];
  int n = populate_grid(grid, argv[1]);

  if(n == -1) {
    printf("Grid file failed to open.\n");
  }
  else if(n == -2) {
    printf("Invalid grid\n");
  }
  while(scanf("%s", str) == 1) {
    for(int a = 0; a < strlen(str); a++) {
      str[a] = tolower(str[a]);
    }
    find_all(grid, n, str, stdout);
  }
  

  return 0;

}

