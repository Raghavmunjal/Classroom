/*
 * Problem-1: Print n numbers in Fibonacci series that are even.  
 * Raghav Munjal 1910990074 17/08/21
 * Assignment 8 - Algorithm
*/

#include <stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n+1];
    arr[0] = 2;
    arr[1] = 8;
    
/*     Fn = Fn-1 + Fn-2 
*    = Fn-2 + Fn-3 + Fn-3 + Fn-4 
*    = Fn-2 + 2Fn-3 + Fn-4 
*    = Fn-3 + Fn-4 + 2Fn-3 + Fn-4
*    = 3Fn-3 + 2Fn-4  
*    = 3Fn-3 + Fn-4 + Fn-5 + Fn-6 
*    = 4Fn-3 + Fn-6  
*/ 
    
    for(i=2;i<n-1;i++){
        arr[i] = 4*arr[i-1] + arr[i-2];
    }
    
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
}
