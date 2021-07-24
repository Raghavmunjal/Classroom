/**
 * program to converts a string of hexadecimal digits into its equivalent integer value
 * Compilation : gcc -o hex_to_int hex_to_int.c
 * Execution : ./hex_to_int
 *
 * @Raghav and 1910990074  25/07/21
 * Assignment -> 1 - C Foundations
 */

#include <stdio.h>
#include <string.h>
#define MAX 1000 

// Declaring a function to convert a string of hexadecimal digits into its equivalent integer value
int htoi(char* str,int n);

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
    

    // Passing string and length of string as an argumnet
    int ans = htoi(str,len);
    
    printf("Output : %d\n",ans);
    
    return 0;
}

/**
 * function to convert a string of hexadecimal digits into its equivalent integer value
 * return type -> int
 */

int htoi(char* str,int n){
    
    // till where we have to calculate integer value ignore 0x,0X
    int i = 0;
    
    // base is 16^0 = 1
    int base = 1;
    
    // resultant value 
    int result = 0;
    
    // Incrementing i with 2 if OX,Ox is present in string
    if(str[0]=='0' && (str[1] == 'x' || str[1] == 'X')){
        i+=2;
    }
    
    // n is length of string
    for(int j = n-1; j >= i; j--)
    {
        if(str[j] >= '0' && str[j] <= '9')
        {
            result += (str[j] - 48) * base;
            base *= 16;
        }
        
        // A->10  B->11 C->12 D->13 E->14 F->15
        else if(str[j] >= 'A' && str[j] <= 'F')
        {
            result += (str[j] - 55) * base;
            base *= 16;
        }
        
        // a->10  b->11 c->12 d->13 e->14 f->15
        else if(str[j] >= 'a' && str[j] <= 'f')
        {
            result += (str[j] - 87) * base;
            base *= 16;
        }
        
    }
    
    return result;
    
}

