#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(void){
  int n, i=0, j=0;
  double x, y, r, s;
  char c;
  char cha[100];
  double num[100];
  double min = 1.797e+308;

  while((c=getchar()) != EOF){
    cha[i++] = c;
  }

  char *ptr = strtok(cha, " \n");
  while (ptr != NULL){
        num[j++] = atof(ptr);
        ptr = strtok(NULL, " \n");
  }

  n = num[0]; x = num[1]; y = num[2];

  for(int p=3; p<2*n+3; p+=2){
    double dis = sqrt(pow(x-num[p], 2) + pow(y-num[p+1], 2));
    if(min>dis){
      min = dis; r = num[p]; s = num[p+1];
    } 
  }

  printf("The closest point from (%0.2f, %0.2f) is (%0.2f, %0.2f) and distance between them is %0.2f\n", x, y, r, s, min);
}