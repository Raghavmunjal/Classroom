/**
 * program to mulitply two matrices
 *
 * Compilation : gcc -o matrix_multiply matrix_multiply.c
 * Execution : ./matrix_multiply
 *
 * @Raghav and 1910990074  24/07/21
 * Assignment -> 1 - C Foundations
 */

#include<stdio.h>    
  
int main(){  
    
    /** 
     * a -> first matrix
     * b -> second matrix
     * res -> result matrix 
     * r1 -> row of first matrix , c1 -> column of first matrix
     * r2 -> row of second matrix , c2 -> column of second matrix
     */

    int a[100][100],b[100][100],res[100][100],r1,c1,r2,c2,i,j,k;    
    
    printf("enter the number of row of first matrix =");    
    scanf("%d",&r1);    
    printf("enter the number of column of first matrix =");    
    scanf("%d",&c1);    
    printf("enter the first matrix element=\n");    
    
    for(i=0;i<r1;i++)    
    {    
        for(j=0;j<c1;j++)    
        {    
            scanf("%d",&a[i][j]);    
        }    
    }

    printf("enter the number of row of second matrix =");    
    scanf("%d",&r2);    
    printf("enter the number of column of second matrix =");    
    scanf("%d",&c2); 
    printf("enter the second matrix element=\n"); 
    
    for(i=0;i<r2;i++)    
    {    
        for(j=0;j<c2;j++)    
        {    
            scanf("%d",&b[i][j]);    
        }    
    }    
    
    // if column of first matrix is not equal to row of second matrix then matrix multiplication is not possible
    if(c1!=r2){
        printf("Invalid Input"); 
        return 0;
    }
    
    // Multiplying two matrices
    for(i=0;i<r1;i++)    
    {    
        for(j=0;j<c2;j++)    
        {    
            res[i][j]=0;    
            for(k=0;k<c1;k++)    
            {    
                res[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }    
    
    printf("Resultant Matrix\n");

    // printing the resultant matrix
    for(i=0;i<r1;i++)    
    {    
        for(j=0;j<c2;j++)    
        {    
            printf("%d ",res[i][j]);    
        }    
        printf("\n");    
    }   
    
        return 0;  
}  
