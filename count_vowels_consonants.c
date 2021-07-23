/**
 * program to count vowels and consonants in a given string
 *
 * Compilation : gcc -o count_vowels_consonants count_vowels_consonants.c
 * Execution : ./counts_vowels_consonants
 *
 * @Raghav and 1910990074  23/07/21
 * Assignment -> 1 - C Foundations
 */

#include <stdio.h>
#include <string.h>
#define MAX 100000

// Declaring Function to count vowels and consonants
void count_vowels_and_consonants(char str[]);

int main(){

    // String str
    char str[MAX];

    printf("Enter the String : ");
    fgets(str,MAX,stdin);

    // Passing string as argument
    count_vowels_and_consonants(str);
    
    return 0;
}

/**
 * function to count vowels and consonants
 * printing there count 
 */

void count_vowels_and_consonants(char str[]){

    int vowels = 0, consonants = 0;
  
    int i;
    char ch;

    for (i = 0; str[i] != '\0'; ++i) {

        // current character of string
        ch = str[i];

        // checking if ch is vowel then increment count of vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' || ch == 'A' ||
            ch == 'E' || ch == 'I' || ch == 'O' ||
            ch == 'U'){
            ++vowels;
        }

        // if ch is consonants then incrementing count of consonants
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            ++consonants;
        }

        //Ignoring the digits
        else if (ch >= '0' && ch <= '9') 
        {
            continue;
        }

        //Ignoring the whitespaces
        else if (ch == ' ') 
        {
            continue;
        }

    }

   printf("Vowels=%d , Consonants=%d\n",vowels,consonants);
}
