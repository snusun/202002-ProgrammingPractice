#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
  int data;
  struct __node* next;
} node;

typedef  struct stk{
  node* head;
  int cnt;
} stk;

void push_stk(stk* S, int n);
void dealloc_stk(stk* S);
/*
void print(stk* S){
  if(S->cnt==0) return;
  node* t = S->head;
  while(t) {
    printf("%d\n", t->data);
    t=t->next;
  }
}*/

int main(void){
  stk* S = (stk*)malloc(sizeof(stk));
  if(!S) return 0;
  S -> head= NULL;
  S -> cnt = 0;

  push_stk(S, 1);
  //print(S);
  push_stk(S, 2);
  //print(S);
  push_stk(S, 3);
  //print(S);
  dealloc_stk(S);
  //print(S);
  return 0;
}

void push_stk(stk* S, int n){
  node* N = (node*)malloc(sizeof(node));
  if(!N) return;
  N->data = n;
  N->next = S->head;
  S->head=N;
  S->cnt++;
}

void dealloc_stk(stk* S){
  while(S->head){
    node* temp = S -> head;
    S->head = S->head->next;
    free(temp);
  }
  free(S);
}