/**
 * program to deletes each character in s1 that matches any character in the string s2
 *
 * Compilation : gcc -o squeeze_string squeeze_string.c
 * Execution : ./squeeze_string
 *
 * @Raghav and 1910990074  25/07/21
 * Assignment -> 1 - C Foundations
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100000

// Declaring a function to deletes each character in s1 that matches any character in the string s2
void squeeze(char s1[],char s2[]);

int main()
{
     // String str1,str2
    char str1[MAX],str2[MAX];

    printf("Enter the First String : ");
    fgets(str1,MAX,stdin);
    
    printf("Enter the Second String : ");
    fgets(str2,MAX,stdin);
    
    // Passing str1 and str2 as an argument
    squeeze(str1,str2);
    
    // Calculating length of string1 after squeezing 
    int len = 0;
    for(int i=0;str1[i]!='\0';i++){
        len++;
    }
    
    // if after squeezing length of string1 is 0 then print -1
    if(len == 0){
        printf("%d",-1);
        return 0;
    }
    
    // else print squeeze string
    printf("%s\n",str1);

    return 0;
}

/**
 * Function to deletes each character in s1 that matches any character in the string s2
 * taking two string as an argument
 * 
 */

void squeeze(char s1[],char s2[])
{
    int i,j,k;
    k=0;
    bool flag = false;
    
    for(i=0;s1[i]!='\0';++i)
    {
        for(int j=0;s2[j]!='\0';++j){
            
            // If character is present in string 2
            if(s1[i]==s2[j])
            {
                flag = true;
                break;
            }
        }
        
        // if character is not present in string 1
        if(flag == false){
            s1[k] = s1[i];
            k++;
        }
    }
    
    s1[k]='\0';
}
