/**
 * program to Write the function strend(char *s , char* t) , 
 * which returns 1 if the string t occurs at the end of the string s, 
 * and zero otherwise
 *
 * Compilation : gcc -o strend strend.c
 * Execution : ./strend
 *
 * @Raghav and 1910990074  26/07/21
 * Assignment -> 1 - C Foundations
 */

#include <stdio.h>
#include <string.h>
#define MAX 100000


/**
 * function strend which returns 1 
 * if the string t occurs at the end of the string s, 
 * and zero otherwise
 *
 * Take str1 -> String 1,str 2-> String 2
 * n1 -> length of first String
 * n2 -> Length of second String
 * as an Arguments
 * 
 * return type -> int
 */

int strend(char *str1, char *str2,int n1,int n2){
    int i, j;

    j = n1 - n2;
    for(i = 0; i < n2; i++){
        if(str1[j] != str2[i])
            return 0;
        j++;
    }
    
    return 1;
}


/**
 *  function to calculate length of string 
 *  return type -> int
 */

int length_of_string(char *str){
    int len = 0;
    for(int i=0;str[i]!='\0';i++){
        len++;
    }
    return len;
}

int main(){
    
  // str1 - > Fisrt String, str2 -> Second String
  char str1[MAX], str2[MAX];

  printf("Enter first string: ");
  scanf("%s", str1);
  printf("Enter second string: ");
  scanf("%s", str2);
  
  // calculating length of First string
  int len1 = length_of_string(str1);
  
  // calculating length of Second string
  int len2 = length_of_string(str2);

  // calling function strend
  int ans = strend(str1,str2,len1,len2);
  
  printf("%d\n", ans);

  return 0;
}
