/**
 * program which returns the first location in the string1 where any character from the string2 occurs
 *
 * Compilation : gcc -o first_location first_location.c
 * Execution : ./first_location
 *
 * @Raghav and 1910990074  25/07/21
 * Assignment -> 1 - C Foundations
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100000

// Declaring a function which returns the first location in the string1 where any character from the string2 occurs
int first_loc(char s1[],char s2[],int n);

int main()
{
     // String str1,str2
    char str1[MAX],str2[MAX];

    printf("Enter the First String : ");
    fgets(str1,MAX,stdin);
    
    printf("Enter the Second String : ");
    fgets(str2,MAX,stdin);
    
    
    // Calculating length of string1 after squeezing 
    int len = 0;
    for(int i=0;str1[i]!='\0';i++){
        len++;
    }
    
    // Passing str1 and str2 as an argument
    int ans = first_loc(str1,str2,len);
    
    
    printf("%d\n",ans);

    return 0;
}

/**
 * function which returns the first location in the string1 where any character from the string2 occurs
 * taking two string as an argument
 * 
 * return type -> int
 */

int first_loc(char s1[],char s2[],int n)
{
    int i,j;
    
    // n is the length of first string
    int ans = n;
    
    for(i=0;s1[i]!='\0';++i)
    {
        for(j=0;s2[j]!='\0';++j){
            
            if(s1[i] == s2[j]){
                
                // first location 
                if(ans > i){
                    ans = i;
                }
                
            }
            
        }
    }
    
    return ans;
    
}
