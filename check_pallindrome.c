/**
 * program to check string is pallindrome or not
 *
 * Compilation : gcc -o check_pallindrome check_pallindrome.c
 * Execution : ./check_pallindrome
 *
 * @Raghav and 1910990074  24/07/21
 * Assignment -> 1 - C Foundations
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100000

// Declaring function to convert all uppercase characters into lowercase
void to_lower_case(char str[]);

//  Declaring function to check string is pallindrome or not
bool isPalindrome(char str[],int n);

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
    
    
    // Convert all uppercase characters into lower case
    to_lower_case(str);
    
    // if isPallindrome return true then string is pallindrome else not pallindrome
    if(isPalindrome(str,len)){
        printf("String is Pallindrome \n");
    }else{
        printf("String is Not Pallindrome \n");
    }
    
    return 0;
}

/*
 * Function to convert uppercase 
 * into lower case characters
 */

void to_lower_case(char str[]){
    
    for(int i=0;str[i]!='\0';i++){
        // if there is an Uppercase character add 32 in ascii value of that character to convert it into lower case
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
    }
    
}

/*
 * Function check whether string is pallindrome or not
 * return type -> bool
 */

bool isPalindrome(char str[],int n){

    int low = 0;
    int high = n-2;
    while(low<high){

        // Ignoring white spaces and continue
        if(str[low]==' ')
        {
            low++;
            continue;
        }

        // Ignoring white spaces and continue
        else if(str[high]==' ')
        {
            high--;
            continue;
        }

        // if at any point character at low and high index are not equal immedialtely return false
        else if(str[low]!=str[high]){
            return false;
        }
        
        
        low++;
        high--;
    }
    
    // if we iterate through the whole string character at low and high index are always equal then we return true
    return true;
}



