#include <stdio.h>

int main(void){
  int n, idx=0, idxHex=0;
  int b[32];
  char h[8];
  printf("n: ");
  scanf("%d", &n);
  int n2=n;

  while(n!=1){
    b[idx++] = n%2;
    n/=2;
  }
  b[idx++] = 1;
  for(int i=idx; i<32; i++){
    b[i] = 0;
  }

  while(n2>=16){
    if(n2%16>=10){
      if(n2%16==10) h[idxHex++] = 'a';
      if(n2%16==11) h[idxHex++] = 'b';
      if(n2%16==12) h[idxHex++] = 'c';
      if(n2%16==13) h[idxHex++] = 'd';
      if(n2%16==14) h[idxHex++] = 'e';
      if(n2%16==15) h[idxHex++] = 'f';
    } else h[idxHex++] = n2%16 + '0';
    n2/=16;
  }
  if(n2>=10){
      if(n2==10) h[idxHex++] = 'a';
      if(n2==11) h[idxHex++] = 'b';
      if(n2==12) h[idxHex++] = 'c';
      if(n2==13) h[idxHex++] = 'd';
      if(n2==14) h[idxHex++] = 'e';
      if(n2==15) h[idxHex++] = 'f';
    } else h[idxHex++] = n2 + '0';
  for(int i=idxHex; i<8; i++){
    h[i] = '0';
  }

  printf("<2진수>\n");
  for(int i=31; i>=0; i--){
    printf("%d", b[i]);
    if(i%8==0) printf(" ");
    if(i==0) printf("\n");
  }
  printf("\n");

  printf("<16진수>\n");
  for(int i=7; i>=0; i--){
    printf("%c", h[i]);
  }
  printf("\n");
}