/*
 * Problem-1: Bit And
 * Raghav Munjal 1910990074 06/08/21
 * Assignment_3 -> Bits and Bytes
*/

#include <stdio.h>

/*
*  bitAnd - x & y using only ~ and |
* Example bitAnd(6, 5) = 4
* Legal ops:  ~ |
* Max ops: 8
*/
int bitAnd (int a, int b){
     return ~(~a | ~b);
}

int main()
{
    int n1,n2;
    printf("Enter Two Numbers :");
    scanf("%d",&n1);
    scanf("%d",&n2);
    int ans;
    ans = bitAnd(n1,n2);
    printf("%d",ans);
    return 0;
}