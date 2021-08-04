/**
 * Program to  Implement a Stack 
 *
 * Compilation : gcc -o implement_stack implement_stack.c
 * Execution : ./implement_stack
 *
 * @Raghav and 1910990074  4/08/21
 * Assignment -> Day_2_Coding_Assignment
 */

#include <stdio.h>
#include <string.h>   

// Intailizing maximum size of stack
int MAXSIZE = 25;

// Intializing stack 
double stack[25];

// Intializing top_index = -1
int top = -1; 

// Function to check if stack is empty
int isEmpty() {

   // top == -1 means stack is empty
   if(top == -1)
      return 1;
   else
      return 0;
   
}

// Function to check if stack is full
int isFull() {

   // if top is equal to capacity of stack then stack is full
   if(top == MAXSIZE-1)
      return 1;
   else
      return 0;

}

// Function to check peek of stack
double peek() {
    
   // if stack is not empty then print top element
   if(!isEmpty()) {
      return stack[top];
   } else {
      printf("Stack Underflow.\n");
      return -1;
   }
   
}

// Function to remove element from top of the stack
double pop() {
   double data;
	
   // if stack is not empty then pop out top item
   if(!isEmpty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Stack Underflow.\n");
      return -1;
   }
}

// Function to insert data in stack
void push(double data) {

   // if stack is not full then insert item into the stack
   if(!isFull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Stack Overflow\n");
   }
}

int size(){
    return top+1;
}

/**
 * Last in first out LIFO
 * push() -> to insert item in stack
 * pop() -> to delete item from top 
 * peek() -> to print top element from stack
 * isEmpty() -> to check stack is empty or not empty
 * isFull() -> to check stack is full or not 
 * size() -> returns size of the stack
 */

int main()
{
    push(10);
    push(20);
    push(3);
    int popped_item = pop();
    printf("Popped item -> %d ",popped_item);
    
    int peek_item = peek();
    printf("\nPeek item -> %d ",peek_item);
    
    
    int ans = isFull();
    if(ans == 1){
        printf("\nStack is Full");
    }else{
       printf("\nStack is Not Full"); 
    }
    
    int res = isEmpty();
    if(res == 1){
        printf("\nStack is Empty");
    }else{
       printf("\nStack is Not Empty"); 
    }
    
    int sizee = size();
    if(sizee == -1){
        printf("\nStack is Empty");
    }else{
       printf("\n%d ",sizee); 
    }
}
