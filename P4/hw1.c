#include <stdio.h>
#include <stdlib.h>

int main(){
  char c;
  int a = 0, num = 0, line = 0, space = 0;
  
  while ((c=getchar()) != EOF) {
    int n = c - '0';
    if(c == 'a') a++;
    else if(n >= 0 && n <= 9) num++;
    else if(c == '\n') line++;
    else if(c == '\t' || c == ' ') space++; 
  }

  printf("a: %d\nnum: %d\nline: %d\nspace: %d\n", a, num, line, space);
  return 0;
}