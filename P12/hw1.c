#include <stdio.h>

#define STACK_SIZE 20

void push(int*, int);
int pop(int*);
void print_stack(int*);

int stk[STACK_SIZE];
int top = -1;

int main(){
  push(stk, 1);
  push(stk, 3);
  push(stk, 5);
  push(stk, 7);
  print_stack(stk);

  return 0;
}

void push(int* stk, int n){
  stk[++top] = n;
}

int pop(int* stk){
  int n = stk[top];
  stk[top--] = 0;
  return n;
}

void print_stack(int* stk){
  while(top>=0){
    printf("%d\n", pop(stk));
  }
}