#include <stdio.h>

void fibo(char c1, char c2, int n);

int main(void) {
  char c1, c2; int n;
  scanf("%c %c %d", &c1, &c2, &n);
  printf("%c %c %d\n", c1, c2, n); 

  fibo(c1, c2, n);
  printf("\n");
}

void fibo(char c1, char c2, int n){
  if(n==0) printf("%c", c1);
  else if(n==1) printf("%c", c2);
  else {
    fibo(c1, c2, n-2);
    fibo(c1, c2, n-1);
  }
}