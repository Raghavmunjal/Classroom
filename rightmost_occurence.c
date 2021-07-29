/*
 *  Program to find rightmost_occurence of string2 in string1
 *  Compilation : gcc -o right_occr right_occr.c
 *  Execution : ./right_occr.c
 *  @Raghav and 1910990074  29/07/21
 *  Assignment -> 1 - C Foundations
*/

#include <stdio.h>
#include <string.h>
#define MAX 100000


/* Function to calculate length of given string
*  Take one strings as a parameter
*  return type-> int
*/
int length_of_string(char *str){
    
    // Calculating length of given string
    int len = 0;
    for(int i=0;str[i]!='\0';i++){
        len++;
    }
    return len;
}

/* Function to find rightmost occurence of s2 in s1
*  Take two strings as a parameter
*  return type-> int
*/

int rightmost_occurence(char *s1, char *s2){

    // len1 -> Length of first string
    int len1 = length_of_string(s1);
    
    // intialize rightmost index with -1
    int indx=-1;

    for(int i=len1-2;i>=0;i--){

    	if(s2[0]==s1[i]){

	    int count=0;
        
        // length of second string
	    int len2 = length_of_string(s2);

	    for(int j=0;s2[j]!='\0' && s1[i+j]!='\0';j++){
	        
    		if(s1[i+j]!=s2[j])
    		    break;
    		
    		else{
    		    
    		    if(s2[j]!='\n'){
		            count++;
		        }
		        
    		}
    		
	    }
	    
    	    if(count==len2-1)
        	    return i;
	    }
    }
    
    return indx;
}

int main(){

    // s1 -> first string s2-> second string
    char s1[MAX];
    char s2[MAX];

    printf("Enter the first string ");
    fgets(s1,MAX,stdin);

    printf("Enter the second string ");
    fgets(s2,MAX,stdin);
    
    // calling function to calculate rightmost_occurence of s2 in s1
    int ans = rightmost_occurence(s1,s2);

    printf("RightMost Index is -> %d\n",ans);

    return 0;
}
