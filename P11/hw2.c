#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  char c1[32], c2[32], c[32];
  int flag=0, i=31, len1=0, len2=0, len=31, d=0;
  printf("Input1 : ");
  scanf("%s", c1);
  len1 = strlen(c1);
  printf("Input2 : ");
  scanf("%s", c2);
  len2 = strlen(c2);

  /* shift */
  int temp1 = len1;
  while(temp1>0){
    c1[len--] = c1[temp1-1];
    temp1--;
  }
  for(int j=0; j<32-len1; j++){
    c1[j] = '0';
  }

  len = 31;
  int temp2 = len2;
  while(temp2>0){
    c2[len--] = c2[temp2-1];
    temp2--;
  }
  for(int j=0; j<32-len2; j++){
    c2[j] = '0';
  }

  for(int j=31; j>=0; j--){
    if(c1[j]=='0' && c2[j]=='0'){
      if(flag==0){
        c[j] = '0';
        flag = 0;
      } else{
        c[j] = '1';
        flag = 0;
      }
    } else if(c1[j]=='0' && c2[j]=='1'){
      if(flag==0){
        c[j] = '1';
        flag = 0;
      } else{
        c[j] = '0';
        flag = 1;
      }
    } else if(c1[j]=='1' && c2[j]=='0'){
      if(flag==0){
        c[j] = '1';
        flag = 0;
      } else{
        c[j] = '0';
        flag = 1;
      }
    } else if(c1[j]=='1' && c2[j]=='1'){
      if(flag==0){
        c[j] = '0';
        flag = 1;
      } else{
        c[j] = '1';
        flag = 1;
      }
    }
  }

  printf("Result: ");
  for(int j=0; j<32; j++){
    if(c[j] == '1'){
      len = 32 - j;
      for(int k=j; k<32; k++){
        printf("%c", c[k]);    
      }
      break;
    }
  }

  for(int j=0; j<32; j++){
    if(c[j]=='1'){
      d += pow(2, 32-j-1);
    }
  }
  printf(" (%d)\n", d);
}