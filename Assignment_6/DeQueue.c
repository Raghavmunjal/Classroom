/*
 * Problem : Implement Deque using Linked list
 * Raghav 1910990074 23/08/21
 * Assignment_6 -> Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node *next;
  struct Node *prev;
};

struct Deque{
  struct Node *front, *rear;
};

typedef struct Node Node;
typedef struct Deque Deque;

Deque *createDeque(){
  Deque *dq = (Deque*)malloc(sizeof(Deque));
  dq->front = dq->rear = NULL;
  return dq;
}

Node *createNode(){
  Node *node = (Node*)malloc(sizeof(Node));
  node->next = node->prev = NULL;
  return node;
}
int is_empty(Deque *dq){
  return dq->front == NULL || dq->rear == NULL;
}
void push_head(Deque *dq, int data){
  Node *node = createNode();
  node->value = data;

  if(is_empty(dq)){
    dq->front = dq->rear = node;
  }
  else{
    node->next = dq->front;
    dq->front->prev = node;
    dq->front = node;
  }
}

void push_tail(Deque *dq, int data){
  Node *node = createNode();
  node->value = data;

  if(is_empty(dq)){
    dq->front = dq->rear = node;
  }
  else{
    node->prev = dq->rear;
    dq->rear->next = node;
    dq->rear = node;
  }
}

int pop_head(Deque *dq){
  if(is_empty(dq))
    return -1;

  int data = dq->front->value;
  dq->front = dq->front->next;
  if(!is_empty(dq))
    dq->front->prev = NULL;
  else
    dq->rear = NULL;

  return data;

}

int pop_tail(Deque *dq){
  if(is_empty(dq))
    return -1;

  int data = dq->rear->value;
  dq->rear = dq->rear->prev;
  if(!is_empty(dq))
    dq->rear->next = NULL;
  else
    dq->front = NULL;

  return data;
}

int peek_head(Deque *dq){
  if(is_empty(dq))
    return -1;

  int data = dq->front->value;
  return data;
}

int peek_tail(Deque *dq){
  if(is_empty(dq))
    return -1;

  int data = dq->rear->value;
  return data;
}

void show(Deque *dq){
    Node *curr = dq->front;
    printf("Deque Elements -> ");
    while(curr != NULL){
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    
  Deque *dq = createDeque();
  push_head(dq, 1);
  push_head(dq, 2);
  push_tail(dq, 3);
  push_tail(dq, 4);
  show(dq);
  printf("%d\n", pop_head(dq));
  printf("%d\n", pop_head(dq));
  printf("%d\n", pop_tail(dq));
  printf("%d\n", pop_tail(dq));
  
}