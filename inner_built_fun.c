/*
 *  Program to write library functions strncat , strcmp and strncpy
 *  Compilation : gcc -o inner_built_fun inner_built_fun.c
 *  Execution : ./inner_built_fun
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

/* Function to copy atmost n characters of s2 in s1
*  Take two strings as a parameter
*/
void strncpy_(char *s1,char *s2,int n)
{
    int indx=0;

    // copy till last character not null and indx is smaller than n
    while(indx<n && s2[indx]!='\0')
    {
        s1[indx] = s2[indx];
        indx++;
    }

    printf("%s",s1);
}


/* Function for string cooncatenation
*  Take two strings as a parameter
*/
void strncat_(char *s1 , char *s2)
{
    int len1=length_of_string(s1);
    int len2=length_of_string(s2);

    //  result = s1 + s2
    char result[len1 + len2 + 1];

    int indx=0;

    // copy all characters of String s1 in ans
    for(int i=0;i<len1;i++)
    {
        result[indx++]=s1[i];
    }

    // copy all characters of String s2 in ans
    for(int i=0;i<len2;i++)
    {
        result[indx++]=s2[i];
    }


    result[indx]='\0';

    printf("%s",result);
}

/* Function for string comparsion
*  take two strings as parameter
*  return type -> int
*/
int strcmp_(char *s1,char *s2)
{

    int len1 = length_of_string(s1);
    int len2 = length_of_string(s2);

    // intialize index to 0
    int indx=0;

    while(indx<len1 && indx<len2)
    {
        // if characters are not Equal
        if(s1[indx]!=s2[indx])
        {
            // return difference of ascii value
            return (int)(s1[indx]-s2[indx]);
        }
        indx++;
    }

    // if both Equal
    if(len1==len2)
    return 0;

    // if string2 is Greater than string1
    if(len1<len2)
    return 1;

    // if string2 is Less than string1
    else
    return -1;
}

int main() {

    // string str1-> First String str2-> Second String
    char s1[MAX];
    char s2[MAX];

    int n;

    printf("Enter string s1 ");
    scanf("%s",s1);

    printf("Enter string s2 ");
    scanf("%s",s2);

    printf("Enter n ");
    scanf("%d",&n);

    printf("Concatenated String -> ");

    // Calling strncat_ to concat two strings
    strncat_(s1,s2);

    printf("\nComparsion -> ");

    // Calling strcmp_ to compare two strings
    int result = strcmp_(s1,s2);

    if(result == 0)
    printf("Both Strings Are Equal");

    else if(result<0)
    printf("String1 is Less than String2");

    else
    printf("String1 is Greater than String2");

    printf("\nCopied String -> ");

    // Calling strncpy_ to copy atmost n characters of s2 in s1
    strncpy_(s1,s2,n);

    printf("\n");

    return 0;
}
 