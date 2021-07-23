/**
 * program to print pyramid pattern
 *
 * Compilation : gcc -o pyramid_pattern pyramid_pattern.c
 * Execution : ./pyramid_pattern
 *
 * @Raghav and 1910990074  23/07/21
 * Assignment -> 1 - C Foundations
 */

#include<stdio.h>

int main() {

    //number n 
    int n;

    printf("Enter number n : ");
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){

        // for printing spaces    
        for(int j=1;j<=n-i;j++){
            printf(" ");
        }

        // for printing hash #
         for(int j=1;j<=i;j++){
            printf("# ");
        }

       printf("\n");

    }
    

    return 0;
}

