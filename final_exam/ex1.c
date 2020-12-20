#include <stdio.h>
#include <string.h>

void print(char *str);

int main(void){
  char str[100];
  scanf("%s", str);
  print(str);
  return 0;
}

void print(char *str){
  int len = strlen(str);
  for(int i=0; i<len; i++){
    int n = str[i] - 0;
    if(n>=97 && n<=122){
      str[i] -= 32;
    } else if(n>=65 && n<=96) {
      str[i] += 32;
    }
  }
  printf("%s\n", str);
}