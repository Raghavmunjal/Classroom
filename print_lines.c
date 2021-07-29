/*
 * Program to print all input lines that are longer than 80 characters
 *
 * Compilation : gcc -o print_lines print_lines.c
 * Execution : ./print_lines
 *
 * Raghav Munjal 1910990074 29/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#define MAX 300


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

int main(){

    char buffer[MAX];

    FILE *file = fopen("file.txt", "r");
  
    // file not found
    if(!file){
        printf("File not Found");
        return 0;
    }

    //iterate till file reaches to its end f end of file 
    while(!feof(file)){
        
        fgets(buffer, MAX, file);
        
        if(length_of_string(buffer) >= 80)
            printf("%s", buffer);
            
    }
    
    // close the file
    fclose(file);
    
    return 0;
}