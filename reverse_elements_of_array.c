/**
 * program to reverse the elements of array
 *
 * Compilation : gcc -o reverse_elements_of_array reverse_elements_of_array.c
 * Execution : ./reverse_elements_of_array
 *
 * @Raghav and 1910990074  24/07/21
 * Assignment -> 1 - C Foundations
 */

#include <stdio.h>

// Declaring function to reverse the elements
void reverse_array_elements(int a[],int n);

int main()
{
    int a[1000],i,n;  
 
    printf("Enter size of array: ");
    scanf("%d",&n);
 
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    
    // Calling a function to reverse content of array
    reverse_array_elements(a,n);
    
    printf("\nElements in array are: ");
    for(i=0;i<n;i++)
 
    {
        printf("%d  ", a[i]);
    }
    
    printf("\n");

    return 0;
}

/* function to reverse
 * taking array and size of array as 
 * an argument
 */

void reverse_array_elements(int a[],int n){
    int low = 0;
    int high = n-1;
    while(low<high){
        int temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        low++;
        high--;
    }
}

