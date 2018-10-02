// search_functions.c
// Teng-Ju Yang tyang28
//
//


#include <stdio.h>
#include "search_functions.h"
#include <string.h>
#include <ctype.h>

/* 
 * Given a filename and a MAX_SIZExMAX_SIZE grid to fill, this function 
 * populates the grid and returns n, the actual grid dimension. 
 * If filename_to_read_from can't be opened, this function returns -1.
 * If the file contains an invalid grid, this function returns -2.
 */
int populate_grid(char grid[][MAX_SIZE], char filename_to_read_from[]){
  int i,j;
  char str[12];
  int rows;
  int columns = 0;
  FILE *input1 = fopen(filename_to_read_from ,"r");
  if(input1 == NULL) {
    return -1;
  }
  fgets(str, 12, input1);
  rows = strlen(str) - 1;
  fclose(input1);
  
  FILE *input = fopen(filename_to_read_from ,"r");
  while(fgets(str, 12, input) != NULL) {
    if(strlen(str) > 10) {
      return -2;
    }
    for(int g = 0; g < 11; g++) {
      if(str[g] == '\n') {
	columns++;
      }
    }
  }
  fclose(input);
  if(rows != columns) {
    return -2;
  }
  FILE *input2 = fopen(filename_to_read_from ,"r");
  for(i = 0; i < rows; i++) {
    for(j = 0; j < columns; j++) {
      fscanf(input2, "%c ", &grid[i][j]);
      grid[i][j] = tolower(grid[i][j]);
      if(isalpha(grid[i][j]) == 0) {
	return -2;
      }
    }    
  }
  return rows;
}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_right(char grid[][MAX_SIZE], int n, char word[], FILE *write_to){
  int count = 0;
  int found;
  int i,j,k;
  int searchlen = strlen(word);
  write_to = stdout;
  for(i = 0; i < n; i++) {
    for(j = 0; j <= n - searchlen; j++) {
      found = 1;
      for(k = 0; k < searchlen; k++) {
	if(grid[i][j+k] != word[k]) {
	  found = 0;
	  break;
	}
      }
      if(found == 1) {
	count++;
	fprintf(write_to, "%s %d %d R\n", word, i, j);
      }
     
    }
  }
  
  return count; // replace this stub
 
}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_left (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){
  
  int count = 0;
  int found;
  int a,b,c;
  int searchlen = strlen(word);
  write_to = stdout;
  for(a = 0; a < n; a++) {
    for(b = n-1; b >= n - searchlen; b--) {
      found = 1;
      for(c = 0; c < searchlen; c++) {
        if(grid[a][b-c] != word[c]) {
          found = 0;
	  break;
        }
      }
      if(found == 1) {
        count++;
	fprintf(write_to, "%s %d %d L\n", word, a, b);
	
      }
     
    }
  }
  return count; 

}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_down (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){

  int count = 0;
  int found;
  int a,b,c;
  int searchlen = strlen(word);
  write_to = stdout;
  for(a = 0; a <= n - searchlen; a++) {
    for(b = 0; b < n; b++) {
      found = 1;
      for(c = 0; c < searchlen; c++) {
        if(grid[a+c][b] != word[c]) {
          found = 0;
          break;
        }
      }
      if(found == 1) {
        count++;
	fprintf(write_to, "%s %d %d D\n", word, a, b);
	
      }

    }
  }
  return count;


}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_up   (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){

  int count = 0;
  int found;
  int a,b,c;
  int searchlen = strlen(word);
  write_to = stdout;
  for(a = n-1; a >= n - searchlen; a--) {
    for(b = 0; b < n; b++) {
      found = 1;
      for(c = 0; c < searchlen; c++) {
        if(grid[a - c][b] != word[c]) {
          found = 0;
          break;
        }
      }
      if(found == 1) {
        count++;
	fprintf(write_to, "%s %d %d U\n", word, a, b);
      }

    }
  }
  return count;


}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_all  (char grid[][MAX_SIZE], int n, char word[], FILE *write_to) {
  
  write_to = stdout;
  int a = find_right(grid, n, word, stdout);
  int b = find_left(grid, n, word, stdout);
  int c = find_down(grid, n, word, stdout);
  int d = find_up(grid, n, word, stdout);
  if((a == 0) && (b == 0) && (c == 0) && (d == 0)){
    fprintf(write_to, "%s - Not Found\n", word);
  }
  return 1;
} 


/*
 * Reads lhs and rhs character by character until either reaches eof.
 * Returns true if the files can be read and the two files match
 * character by character. Returns false if two files either can't be
 * opened or don't match. The definition of this function is provided 
 * for you.
 */
int file_eq(char lhs_name[], char rhs_name[]) {
  FILE* lhs = fopen(lhs_name, "r");
  FILE* rhs = fopen(rhs_name, "r");

  // don't compare if we can't open the files
  if (lhs == NULL || rhs == NULL) return 0;

  int match = 1;
  // read until both of the files are done or there is a mismatch
  while (!feof(lhs) || !feof(rhs)) {
	if (feof(lhs) ||                      // lhs done first
		feof(rhs) ||                  // rhs done first
		(fgetc(lhs) != fgetc(rhs))) { // chars don't match
	  match = 0;
	  break;
	}
  }
  fclose(lhs);
  fclose(rhs);
  return match;
}

