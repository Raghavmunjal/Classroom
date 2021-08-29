/*
 * Problem : Implement Queue using Linked List
 * Raghav 1910990074 26/08/21
 * Assignment_6 -> Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	struct Node* next;
};

struct Queue {
	struct Node *front, *rear;
};

struct Node* newNode(int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->value = data;
	temp->next = NULL;
	return temp;
}

struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

int is_empty(struct Queue* q){
  return q->front == NULL;
}

int peek(struct Queue* q){
  if(is_empty(q))
    return -1;
  int data = q->front->value;
  return data;
}

void enQueue(struct Queue* q, int data)
{
	
	struct Node* temp = newNode(data);

	
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
}

void deQueue(struct Queue* q)
{
	
	if (q->front == NULL)
		return;

	
	struct Node* temp = q->front;

	q->front = q->front->next;

	
	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}

int main()
{
	struct Queue* q = createQueue();
	enQueue(q, 10);
	enQueue(q, 20);
	printf("%d \n", peek(q));
	deQueue(q);
	deQueue(q);
	printf("%d \n", is_empty(q));
	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 50);
	printf("%d \n", peek(q));
	deQueue(q);
	printf("Queue Front : %d \n", q->front->value);
	printf("Queue Rear : %d\n", q->rear->value);
	printf("%d \n", is_empty(q));
	return 0;
}
