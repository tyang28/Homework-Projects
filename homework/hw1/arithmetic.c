/** Teng-Ju Yang Hw1                                                                                                                                                                                                               
 *  tyang28                                                                                                                                                                                                                        
 */
#include <stdio.h>
#include <string.h>

int main () {
  int l = 100;
  char exp[l];
  printf("b\n");
  printf("Please enter an arithmetic expression using * and / only:\n");
  while (fgets(exp, l, stdin) != NULL) {
    /*
    printf("%c\n", exp[0]);
    printf("%c\n", exp[1]);
    printf("%c\n", exp[2]);
    printf("%c\n", exp[3]);
    */
    for(int i = 0; i < strlen(exp); i++) { 
      if((exp[i] == '*' && exp[i+1] == '/') || (exp[i] == '/' && exp[i+1] == '*') || (exp[i] == '*' && exp[i+1] == '*') || (exp[i] == '/' && exp[i+1] == '/')){
	printf("malformed formula\n");
	return 0;
      }
      else if(exp[i] == '/' && exp[i+1] == '0') {
	printf("division by zero\n");
	return 0;
      }
    }
    char *num;
    num = strtok(exp, " ");
    //printf("%s\n", num);
    
    while (num != NULL) {
      printf("%s\n", num);
      atof(num);
      /*
      if(num == '*') {
	
      }
      */
      num = strtok(NULL, " ");
    }
    
    
  }
  return 0;
}
