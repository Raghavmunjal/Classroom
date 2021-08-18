/*
 * Problem-2: Bit Xor
 * Raghav Munjal 1910990059 06/08/21
 * Assignment_3 -> Bits and Bytes
*/


#include <stdio.h>

/*
*  bitXor - x ^ y using only ~ and &
* Example bitXor(4, 5) = 1
* Legal ops:  ~ &
* Max ops: 14
*/
int bitXor (int a, int b) {
    return ~(~(a&~b) & ~(~a&b));
}

int main()
{
    int n1,n2;
    printf("Enter Two Numbers :");
    scanf("%d",&n1);
    scanf("%d",&n2);
    int ans;
    ans = bitXor(n1,n2);
    printf("%d",ans);
    return 0;
}