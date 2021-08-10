/*
 * Problem-1: Balanced Parentheses: Write a program that checks whether the
   sequence of brackets in the given string is balanced or not.
 * Raghav Munjal 1910990074 10/08/21
 * Assignment_4 -> Stack and Queue
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100000

bool isValid(char * s){
    if(s == "") return true;
    char stack[MAX];
    int sz = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            stack[sz] = s[i];
            sz++;
        }
        else{
            switch (s[i]){
                case ')':{
                    if(sz -1 < 0 || stack[sz-1] != '(') return false;
                    else sz--;
                    break;
                }
                case '}':{
                    if(sz-1 < 0 || stack[sz-1] != '{') return false;
                    else sz--;
                    break;
                }
                case ']':{
                    if(sz-1 < 0 || stack[sz-1] != '[') return false;
                    else sz--;
                    break;
                }
            }
        }
    }
    if(sz == 0) return true;
    else return false;
}

int main()
{
    char str[MAX];

    printf("Enter the String : ");
    fgets(str,MAX,stdin);
    
    bool ans = isValid(str);
    
    if(ans == true){
        printf("Valid Paranthesis");
    }else{
        printf("Not Valid Paranthesis"); 
    }
    
    
}
