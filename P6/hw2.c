#include <stdio.h>

int main(void){
  int dec, len;
  int bi[20];
  scanf("%d", &dec);

  for(len=0; dec>0; len++){
    bi[len] = dec % 2;
    dec = dec / 2;
  }

  for(int j=len-1; j>=0; j--){
    printf("%d", bi[j]);
  }
  printf("\n");

}