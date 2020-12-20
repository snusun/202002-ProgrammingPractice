#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20

typedef struct __node{
  int data;
  struct __node* next;
}node;

typedef struct __list{
  node* head;
  int cnt;
}list;

void push(list*, int);
int pop(list*);
void print_stack(list*);

int main(){
  list* stk = (list*)malloc(sizeof(list));
  stk->cnt = 0;
  push(stk, 1);
  push(stk, 3);
  push(stk, 5);
  push(stk, 7);
  print_stack(stk);

  return 0;
}

void push(list* stk, int n){
  node* N = (node*)malloc(sizeof(node));
  if(!N){
    return;
  }
  N->data = n;
  N->next = stk->head;
  stk->head = N;
  stk->cnt++;
}

int pop(list* stk){
  if(stk->cnt == 0){
    printf("Empty\n");
    return 0; 
  }
  int idx;
  node* curr = stk->head;
  node* prev = NULL;
    
  int n = stk->head->data;
  stk->head = stk->head->next;
  free(curr);
  
  stk->cnt--;
  return n;
}

void print_stack(list* stk){
  while(stk->cnt>0) {
    printf("%d\n", pop(stk));
  }
}