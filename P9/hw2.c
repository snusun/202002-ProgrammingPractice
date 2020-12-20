#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
  char c;
  char num[100];
  int m[18], output[9];
  int i=0, j=0;

  while((c=getchar()) != EOF){
    num[i++] = c;
  }

  char *ptr = strtok(num, " \n");
  
  while (ptr != NULL){
    m[j++] = atoi(ptr);
    ptr = strtok(NULL, " \n");
  }

  output[0] = m[0]*m[9] + m[1]*m[12] + m[2]*m[15];
  output[1] = m[0]*m[10] + m[1]*m[13] + m[2]*m[16];
  output[2] = m[0]*m[11] + m[1]*m[14] + m[2]*m[17];
  
  output[3] = m[3]*m[9] + m[4]*m[12] + m[5]*m[15];
  output[4] = m[3]*m[10] + m[4]*m[13] + m[5]*m[16];
  output[5] = m[3]*m[11] + m[4]*m[14] + m[5]*m[17];
  
  output[6] = m[6]*m[9] + m[7]*m[12] + m[8]*m[15];
  output[7] = m[6]*m[10] + m[7]*m[13] + m[8]*m[16];
  output[8] = m[6]*m[11] + m[7]*m[14] + m[8]*m[17];
  
  for(int l=0; l<7; l+=3)
    printf("%5d %5d %5d\n", output[l], output[l+1], output[l+2]);
    
}