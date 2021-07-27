/**
 * Program to check Selection_sort runtime analysis
 *
 * Compilation : gcc -o Selection_sort Selection_sort.c
 * Execution : ./Selection_sort
 *
 * @Raghav and 1910990074  26/07/21
 * Assignment -> Day2_Coding_Assignment
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* Function to generate Input
* type 1-> Random Numbers
* type 2-> Sorted Numbers in Ascending Order
* type 3-> Sorted Numbers in Descending Order
*/

void Input_generator(int arr[],int n,int type){
    
    if(type == 1) {
        
        // random -> rand()
        for(int i=0;i<n;i++){
            arr[i] = rand() % n + 1;
        }
        
    }
    else if(type == 2) {
        
        for(int i=0;i<n;i++){
            arr[i] = i;
        }
        
    }
    else if(type == 3) {
        
        for(int i=0;i<n;i++){
            arr[i] = n-i-1;
        }
        
    }
    
    
}


/*
* Function to Swap two numbers
*/
void swap(int arr[],int i,int j){
    
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
}

/*
* Selection Sort Algorithm
* In Place and UnStable
* Does less Memory Writes
*/

void selection_sort(int arr[],int n){
   
   for(int i = 0; i < n; i++){
        int min_index = i;
        
        // Finding minimum element and swap with current position  
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        
        // swap if min_index is not equal to i.  
        if(min_index!=i){
            swap(arr,min_index,i);
        }
    } 
   
}

/*
* Function to calculate_time for different type of input
* intial_size -> 8000
* increment -> 4000
*/

void calculate_time(int intial_size,int increment,int type){
    struct timeval te;
    int i;
    
    for(i=0;i<8;i++){
        
        int size = intial_size + increment*i;
        int arr[size];
        
        // Calling Function for generating Input
        Input_generator(arr,size,type);
        
        gettimeofday(&te,NULL);
        
        // sec*1000 + microseconds/1000 == milliseconds 
        long long start_time = te.tv_sec * 1000LL + te.tv_usec / 1000;
        
        // Calling selection_sort to sort array
        selection_sort(arr,size);
        
        gettimeofday(&te,NULL);
        
        long long end_time = te.tv_sec * 1000LL + te.tv_usec / 1000;
        
        printf("\t %lld",end_time - start_time);
    }
    
}

int main()
{
    int intial_size = 8000;
    
    int increment = 4000;
    
    printf("Time Taken By Random Numbers");
    
    // type 1-> Random Numbers
    calculate_time(intial_size,increment,1);
    
    printf("\n");
    
    printf("Time Taken By Sorted Numbers in Ascending Order");
      
    // type 2-> Sorted Numbers in Ascending Order 
    calculate_time(intial_size,increment,2);
        
    printf("\n");
    
    
    printf("Time Taken By Sorted Numbers in Descending Order");
     
    // type 3-> Sorted Numbers in Descending Order  
    calculate_time(intial_size,increment,3);
        
    printf("\n");
    
    

    return 0;
}