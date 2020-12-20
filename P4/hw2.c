#include <stdio.h>
int main(){
  for(int i=5; i>0; i--){
    for(int j=i; j<=4; j++) printf(" ");
    for(int k=i*2-1; k>=1; k--) printf("*");
    printf("\n");
  }
  for(int i=1; i<5; i++){
    for(int j=4; j>i; j--) printf(" ");
    for(int k=1; k<=i*2+1; k++) printf("*");
    printf("\n");
  }
}