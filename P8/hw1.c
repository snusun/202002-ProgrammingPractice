#include<stdio.h>
#include<string.h>

void swap(char** , char**);
void bubble_sort(char* words[10]);

int main(void) {
  char* words[10] = {
    "computer", "windows", "window", "linux",
    "apple", "banana", "time", "help",
    "game", "money"};  
  bubble_sort(words);
  for(int i = 0; i < 10; i++){
    printf("%s\n", words[i]);
  }
}

void swap(char** a, char** b){
  char* t = *a;
  *a = *b;
  *b = t;
}

void bubble_sort(char* words[10]){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10 - 1; j++){
      if (strlen(words[j]) > strlen(words[j + 1]))
        swap(&words[j], &words[j+1]);
            
      if (strlen(words[j]) == strlen(words[j + 1]))
        if(strcmp(words[j], words[j+1]) > 0)
          swap(&words[j], &words[j+1]);
    }
  }
}
