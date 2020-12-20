#include <stdio.h> 

int count_sosu(int n);

int main(void){ 
  int num;
  scanf("%d",&num);  
  printf("Count: %d\n", count_sosu(num));
  return 0;
}

int count_sosu(int n){
  int prime, sosu, i, count=0;
  int num = n;
  sosu=2;
  while(sosu<num){ 
    prime=1; 
    for(i=2;i<sosu;i++){
      if(sosu % i == 0){ 
        prime=0; break;
      } 
    } 
    if(prime == 1) {
      printf("%d ", sosu);
      printf("is sosu\n");
      count++;
    }
    sosu++;  
  } 
  return count;
}