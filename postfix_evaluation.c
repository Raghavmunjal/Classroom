    /*
 * Program which evaluates a reverse Polish expression
 *
 * Compilation : gcc -o  postfix_evaluation.c
 * Execution : ./postfix_evaluation
 *
 * Raghav Munjal 1910990074 29/07/21
 * Assignment_1 -> C Foundation
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
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

// Function to check if stack is full
int isfull() {

   if(top == MAXSIZE-1)
      return 1;
   else
      return 0;
}

// Function to check peek of stack
double peek() {
    
   if(!isempty()) {
      return stack[top];
   } else {
      printf("Stack Underflow.\n");
   }
   
}

// Function to remove element from top of the stack
double pop() {
   double data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Stack Underflow.\n");
   }
}

// Function to insert data in stack
void push(double data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Stack Overflow\n");
   }
}

double eval(double a, double b, char ch){
    if(ch == '+'){
        return a + b;
    }
    else if(ch == '-'){
        return a - b;
    }
    else if(ch == '/'){
        return a / b;
    }
    else{
        return a * b;
    }
}

void expr(int n){
    
    double a, b, result;
    char ch;

    for(int i = 0; i < n; i++){
        
        scanf(" %c", &ch);

        if(isdigit(ch)){
          push(ch-48);
        }
        
        else{
          a = pop();
          b = pop();
    
          result = eval(a, b, ch);
          push(result);
        }
    }
    printf("%.1lf",result);
}


int main(){
    int n;
    printf("Enter no. of Elements: ");
    scanf("%d", &n);
    expr(n);
    return 0;
}