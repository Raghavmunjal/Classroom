/*
 * Problem-5: Logical Shift
 * Raghav Munjal 1910990074 15/08/21
 * Assignment_3 -> Bits and Bytes
*/

#include <stdio.h>

/* logicalShift - shift x to the right by n, using a logical shift
*  can assume that 0 <=n<=31
* examples: logicalShift(0x87654321, 4) = 0x8765432
*  Legal ops:  ~ & ^ | + << >>
*Max ops: 20
*/
int logicalShift(int x, int n) {
    // x = x>>1 & 2147483647;
    x = x>>1 & 0x7fffffff;
    return (x >> (n-1));
}

int main()
{   
    int x;
    //Taking input of a number  
    scanf("%x", &x);
    int n;
    scanf("%d",&n);
    printf("%x",logicalShift(x,n));
    return 0;
}

