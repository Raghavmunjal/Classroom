/*
 * Problem-2: Infix to Postfix: Write a program that converts an arithmetic
   expression from infix notation to postfix notation. 
 * Raghav Munjal 1910990074 10/08/21
 * Assignment_4 -> Stack and Queue
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100000


struct Stack
{
    int top;
    int capacity;
    int* arr;
};
 

struct Stack* createStack( int capacity )
{
    struct Stack* stack = (struct Stack*)
           malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
 
    stack->arr = (int*) malloc(stack->capacity *
                                   sizeof(int));
 
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
    return stack->arr[stack->top];
}
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->arr[stack->top--] ;
    return '~';
}
void push(struct Stack* stack, char op)
{
    stack->arr[++stack->top] = op;
}
 
 

int isOperand(char ch)
{

    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    else
        return 0;
}
 

int Precedence(char ch)
{
    
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='^'){
        return 3;
    }
    else{
        return -1;
    }
    
}
 
 

int infixToPostfix(char* str)
{
    int i, curr;
 
    
    struct Stack* stack = createStack(strlen(str));
    if(!stack) 
        return -1 ;
    
    curr = -1;
    for (i = 0; str[i]!='\0'; ++i)
    {
         
       
        if (isOperand(str[i]))
            str[++curr] = str[i];
        
      
        else if (str[i] == '(')
            push(stack, str[i]);
         
        
        else if (str[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                str[++curr] = pop(stack);
            
            
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;            
            else
                pop(stack);
        }
        else 
        {
            while (!isEmpty(stack) && Precedence(str[i]) <= Precedence(peek(stack)))
                str[++curr] = pop(stack);
                
            push(stack, str[i]);
        }
 
    }
 
    
    while (!isEmpty(stack))
        str[++curr] = pop(stack );
 
    str[++curr] = '\0';
    printf( "%s", str );
}


int main()
{
    char str[MAX];

    printf("Enter the String : ");
    fgets(str,MAX,stdin);
    infixToPostfix(str);
    return 0;
}