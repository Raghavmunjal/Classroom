/**
 * program to sort the array using recursive selection_sort
 *
 * Compilation : gcc -o selection_sort selection_sort.c
 * Execution : ./selection_sort
 *
 * @Raghav and 1910990074  4/08/21
 * Assignment -> 5 Recursion
 */

#include <stdio.h>

//function to swap two elements
void swap(int arr[],int i,int j){
    
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
}

// function to find minIndex
int minIndex(int arr[], int i, int j)
{
    if (i == j)
        return i;
 
    int k = minIndex(arr, i + 1, j);
 
    return (arr[i] < arr[k]) ? i : k;
}

// function to sort the array
void selection_sort(int arr[],int n,int indx){
    if(indx == n)
        return;
    
    int k = minIndex(arr,indx,n-1);
    
    // if minIndex is not equal to current index then swap minIndex with current index
    if(k!=indx){
        swap(arr,k,indx);
    }
    
    selection_sort(arr,n,indx+1);
    
}

int main()
{
    int number,a;

    printf("Enter the number of elements:");    
    scanf("%d",&number);

    int arr[number];
    
    for(int i=0;i<number;i++){
        scanf("%d",&a);
        arr[i] = a;
    }
    
    // calling functions to sort the array
    selection_sort(arr,number,0);
    
    for(int i=0;i<number;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}
