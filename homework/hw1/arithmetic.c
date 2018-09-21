/** Teng-Ju Yang Hw1                                                                                                               
 *tyang28                                                                                                                          
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
  float num1;
  float num2;
  float final = 0.0;
  char oper;
  char oper2;
  char buff[100];

  printf("Please enter an arithmetic expression using * and / only:\n");
 
  if(scanf("%f", &num1) == 1) {
  
    while(scanf(" %c %f", &oper, &num2) == 2) {
  
      if((oper != '*') && (oper != '/')) {
	printf("malformed formula\n");
	return 0;
      }
      else if((oper == '/' && num2 == 0)) {
	printf("division by zero\n");
	return 0;
      }
      else if(oper == '*') {
	num1 *=  num2;
      }
      else if(oper == '/') {
	num1 /=  num2;
      }
      final = num1;
      printf("%f\n", final);      
    }

  }
  else {
    printf("malformed formula\n");
  }
  
  return 0; 
    
}
