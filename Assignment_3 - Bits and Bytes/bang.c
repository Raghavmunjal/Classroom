/*
 * Problem-5: Bang
 * Raghav Munjal 1910990074 15/08/21
 * Assignment_3 -> Bits and Bytes
*/

#include <stdio.h>

/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12
*/
int bang(int x) {
    
    // ~x+1 = -x
    // n<0 x>>31 = -1 ,-x>>31 = 0
    // n>0 x>>31 = 0 , -x>>31 = 1
    // n=0 x>>31 = 0 , -x>>31 = 0
   
    return (((x>>31) + ((~x+1)>>31))) + 1;
}

int main()
{   
    int x;
    //Taking input of x  
    scanf("%d", &x);
    printf("%d",bang(x));
    return 0;
}