/**
 * program to reverse the given string
 *
 * Compilation : gcc -o reverse_string reverse_string.c
 * Execution : ./reverse_string
 *
 * @Raghav and 1910990074  25/07/21
 * Assignment -> 1 - C Foundations
 */

#include <stdio.h>
#include <string.h>
#define MAX 100000

// Declaring Function to reverse the given String
void reverse(char* str,int n);

int main()
{
    // String str
    char str[MAX];

    printf("Enter the String : ");
    fgets(str,MAX,stdin);
    
    // Calculating length of given string
    int len = 0;
    for(int i=0;str[i]!='\0';i++){
        len++;
    }
    

    // Passing string as argument
    reverse(str,len);
    
    printf("Reverse of the string: %s\n", str);
    
    return 0;
}

/**
 * Function to reverse the given string
 * Using two Pointers
 */

void reverse(char* str,int n){
    
    // n is the length of string
    int low = 0;
    int high = n-1;
    
    while(low<high){
        
        // swapping characters at low and high index
        char ch = str[low];
        str[low] = str[high];
        str[high] = ch;
        
        low++;
        high--;
    }

}


