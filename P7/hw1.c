#include <stdio.h>
#include <stdlib.h>

int read_and_calc(){
  char a[100], sym[100];
  int num[100];
  int f=0, n=0, s=0, k=0, sum=0;
  char c;

  while((c=getchar()) != EOF){
    a[f++] = c;
  }

  for(int j=0; j<f; j++){
    if(a[j] == '+' || a[j] == '-'){
      sym[s++] = a[j];
    } else {
      num[n++] = a[j] - '0'; //easy to convert char to int
    }
  }

  sum = num[0];
  for(int j=1; j<n; j++){
    if(sym[k] == '+'){
      sum += num[j];
    } else if(sym[k] == '-') sum -= num[j];
    k++;
  }
  return sum;
}

int main(void){
  printf("result: %d\n", read_and_calc());
  return 0;
}