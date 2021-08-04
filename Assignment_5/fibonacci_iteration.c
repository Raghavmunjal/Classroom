 /**
 * Program to  print n times the every third element of the fibonacci series.
 *
 * Compilation : gcc -o fibonacci fibonacci.c
 * Execution : ./fibonacci
 *
 * @Raghav and 1910990074  4/08/21
 * Assignment -> 5_Recursion
 */

#include<stdio.h>    
int main()    
{    
    int a=1,b=1,c,i,number;
    
    printf("Enter the number of elements:");    
    scanf("%d",&number); 
    
    for(i=2;i<number*3;++i) 
    {    
        c = a+b;
        
        // printing every 3rd element of fibonacci series
        if((i+1) % 3==0){
           printf(" %d",c);  
        }
        
        a = b;    
        b = c;    
    }  
    
    return 0;  
}    