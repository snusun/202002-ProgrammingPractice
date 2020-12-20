#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;

int main(void){
  char str[100];
  bool is_sym;
  int count=0;
  
  //input string
  printf("input string: ");
  scanf("%s", str);

  //counting
  for(int i=0; i<100; i++){
    if(str[i] != '\0'){
      count++;
    }
    if(str[i] == '\0'){
      break;
    }
  }

  for(int i=0; i<count/2; i++){
    if(strcmp(str, "")) is_sym = true;
    if(str[i] != str[count-1-i]){
      is_sym = false;
      break;
    }
    is_sym = true;
  }

  if(strlen(str) == 1){
    is_sym = true;
  }
  
  if(is_sym == true)
    printf("%s is a symmetrical word\n", str);
  else if(is_sym == false)
    printf("%s is not a symmetrical word\n", str);
}