#include <stdio.h>
#include <string.h>   

int MAXSIZE = 25;       
int stack[25];     
int top = -1; 

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
    
   if(!isempty()) {
      return stack[top];
   } else {
      printf("Stack Underflow.\n");
   }
   
}

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Stack Underflow.\n");
   }
}

int push(int data) {

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
        
        scanf(" %c ", &ch);

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