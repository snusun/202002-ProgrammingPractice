/*
* Programming Practice week 10
* Singly Linked List 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
  int data;
  struct __node* next;
}node;

typedef struct __list{
  node* head;
  int cnt;
}list;

void clear_list(list*);
void append_node(list*);
void insert_node(list*);  
void delete_node(list*);
void print_list(list*);
void reverse_list(); //hw1
void sort_list();    //hw2

int main(){
  printf("\033[2J\033[H"); //clear screen
  printf("\t**week10 practice**\n");
  /* init a list */
  list* L = (list*)malloc(sizeof(list));
  if(!L) printf("Failed to Init.\n");
  L->head = NULL;
  L->cnt = 0;
  while(1){
    printf("a : append   i : insert  d : delete\nr : reverse  s : sort    p : print\nq : quit\n");
    printf("Press key : ");    
    char c = getchar();
    getchar(); // remove '\n'   
    printf("\033[2J\033[H"); //clear screen   
    switch(c){
      case 'a' : append_node(L);  break;
      case 'i' : insert_node(L);  break;
      case 'd' : delete_node(L);  break;
      case 'r' : reverse_list(L); break;
      case 's' : sort_list(L);    break;
      case 'p' : print_list(L);   break;
      case 'q' : clear_list(L);   return 0;
      default : printf("Invalid Key\n");
    }
  }
  return 0;
}

void clear_list(list* L){
  while(L->head){
    node* tmp = L->head;
    L->head = L->head->next;
    free(tmp);
  }
  free(L);
}

void append_node(list* L){
  node* N = (node*)malloc(sizeof(node));
  if(!N){
    printf("Failed to create a node\n");
    return;
  }
  int n;
  printf("Data : ");
  scanf("%d", &n);
  getchar(); // remove '\n'
  N->data = n;
  N->next = L->head;
  L->head = N;
  L->cnt++;
  printf("\033[2J\033[H"); //clear screen
  printf("\t Append succeeded\n");   
}

void insert_node(list* L){
  /* implement this function */  
  int idx, n;
  printf("Index(0~) : ");
  scanf("%d", &idx);
  getchar(); // remove '\n'
  printf("\033[2J\033[H"); //clear screen
  if(idx == 0){ //equals to append
    append_node(L);
    return;
  }
  else if(idx > L->cnt || idx < 0){
    printf("Invalid Index\n");
    return;
  }  
  node* N = (node*)malloc(sizeof(node));
  if(!N){
    printf("Failed to create a node\n");
    return;
  }
  printf("Data : ");
  scanf("%d", &n);
  getchar(); // remove '\n'
  node* t = L->head;
  while(idx-- != 1){    
    t = t->next;    
  }
  N->data = n;
  N->next = t->next;
  t->next = N;
  L->cnt++;
  printf("\033[2J\033[H"); //clear screen
  printf("\t Insert succeeded\n");
}

void delete_node(list* L){
  if(L->cnt == 0){
    printf("Empty\n");
    return;
  }
  int idx;
  node* curr = L->head;
  node* prev = NULL;
  printf("Index(0~) : ");
  scanf("%d", &idx);
  getchar(); // remove '\n'
  printf("\033[2J\033[H"); //clear screen
  if(idx > L->cnt-1 || idx < 0){
    printf("Invalid Index\n");
    return;
  }
  else if(idx == 0){
    L->head = L->head->next;
    free(curr);
  }
  else{    
    while(idx--){
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
  }
  L->cnt--;
  printf("\t Delete succeeded\n");
}

void print_list(list* L){
  if(L->cnt == 0){
    printf("Empty\n");
    return;
  }
  node* t = L->head;
  while(t){
    printf("%d ", t->data);
    t = t->next;
  }
  printf("\n");
}

void reverse_list(list* L){
  /* hw1 */
  node* curr = L->head;
  node* prev = NULL;
  if(L->head != NULL){
    prev = L->head;
    curr = L->head->next;
    L->head = L->head->next;

    prev->next = NULL; // Make first node as last node

    while(L->head != NULL){
      L->head = L->head->next;
      curr->next = prev;
      prev = curr;
      curr = L->head;
    }

    L->head = prev; // Make last node as head

    printf("SUCCESSFULLY REVERSED LIST\n");
    }
}

void sort_list(list* L){
  /* hw2 */
  node* curr = L->head;
  node* index = NULL;  
  int temp;  
          
  if(L->head == NULL){  
    return;  
  }  
  else{  
    while(curr != NULL){  
      index = curr->next;  
        
      while(index != NULL){
          if(curr->data > index->data){  
              temp = curr->data;  
              curr->data = index->data;  
              index->data = temp;  
          }  
          index = index->next;  
      }  
      curr = curr->next;  
    }      
  }  
}
