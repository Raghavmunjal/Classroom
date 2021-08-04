/**
 * program to find gcd of two numbers
 *
 * Compilation : gcc -o gcd_of_two_numbers gcd_of_two_numbers.c
 * Execution : ./gcd_of_two_numbers
 *
 * @Raghav and 1910990074  4/08/21
 * Assignment -> 5 Recursion
 */

#include <stdio.h>

 /**
 * Function to find gcd
 * return type -> int
 */
int gcd(int a,int b){
    
    if(b==0)
    return a;
    
    return gcd(b,a%b);
    
}

int main()
{
    // a ->first number b->second number
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);

    // calling function to find gcd
    int ans = gcd(a,b);
    
    printf("Gcd of %d and %d is -> %d",a,b,ans);
    
}
