/**
 * program to swap two numbers without using third variable
 *
 * Compilation : gcc -o swap_two_numbers swap_two_numbers.c
 * Execution : ./swap_two_numbers
 *
 * @Raghav and 1910990074  23/07/21
 * Assignment -> 1 - C Foundations
 */

#include<stdio.h>

int main() {
    
    //Two Number a and b
    int a;
    int b;

    printf("Enter first number a : ");
    scanf("%d",&a);
    printf("Enter second number b : ");
    scanf("%d",&b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a : %d , b : %d \n",a,b);

    return 0;
}
