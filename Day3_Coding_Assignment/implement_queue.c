/**
 * Program to  Implement a circular queue 
 *
 * Compilation : gcc -o implement_queue implement_queue.c
 * Execution : ./implement_queue
 *
 * @Raghav and 1910990074  4/08/21
 * Assignment -> Day_2_Coding_Assignment
 */

#include <stdio.h>
#include <string.h>   

// Intailizing maximum size of queue
int MAXSIZE = 25;

// Intializing queue 
double queue[25];

int front = 0; 
int rear  = 24;
int sz = 0;

// Function to check if queue is empty
int isEmpty() {

   // if size of queue is 0 then queue is empty
   if(sz == 0)
      return 1;
   else
      return 0;
}

// Function to check if queue is full
int isFull() {

   if(sz == MAXSIZE)
      return 1;
   else
      return 0;
}

// Function to check peek of queue
double peek() {
    
   if(!isEmpty()) {
      return queue[front];
   } else {
      printf("Queue Underflow.\n");
      return -1;
   }
   
}

// Function to remove element from front of the queue
double dequeue() {
   double data;
	
   if(!isEmpty()) {
      data = queue[front];
      front = (front + 1) % MAXSIZE;
      sz--;
      return data;
   } else {
      printf("Queue Underflow.\n");
      return -1;
   }
}

// Function to insert data in Queue
void enqueue(double data) {

   if(!isFull()) {
      rear = (rear + 1) % MAXSIZE;   
      queue[rear] = data;
      sz++;
   } else {
      printf("Stack Overflow\n");
   }
}

int size(){
    return sz;
}

/**
 * First in first out FIFO
 * enqueue() -> to insert item at rear end in queue
 * dequeue() -> to delete item from front
 * peek() -> to print front element 
 * isEmpty() -> to check queue is empty or not empty
 * isFull() -> to check queue is full or not 
 * size() -> returns size of the stack
 */

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(3);
    int popped_item = dequeue();
    printf("Popped item -> %d ",popped_item);
    
    int peek_item = peek();
    printf("\nPeek item -> %d ",peek_item);
    
    
    int ans = isFull();
    if(ans == 1){
        printf("\nQueue is Full");
    }else{
       printf("\nQueue is Not Full"); 
    }
    
    int res = isEmpty();
    if(res == 1){
        printf("\nQueue is Empty");
    }else{
       printf("\nQueuek is Not Empty"); 
    }
    
    int sizee = size();
    if(sizee == -1){
        printf("\nQueue is Empty");
    }else{
       printf("\n%d ",sizee); 
    }
}
