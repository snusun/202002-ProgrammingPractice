#include <stdio.h>

int main(void){
  int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
  scanf("%d %d %d %d %d %d %d %d %d %d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10);

  int n[10];
  n[0]=n1; n[1]=n2; n[2]=n3; n[3]=n4; n[4]=n5;
  n[5]=n6; n[6]=n7; n[7]=n8; n[8]=n9; n[9]=n10;

  int max=1; int tmp=1;
  for(int i=1; i<10; i++){
    if(n[i-1]+1 == n[i]) tmp++;
    else tmp = 1;
    if(max<tmp) max=tmp;
  }
  printf("%d\n", max);
  return 0;
}