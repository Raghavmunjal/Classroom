/*
 * Problem-4: Get Byte
 * Raghav Munjal 1910990059 12/08/21
 * Assignment_3 -> Bits and Bytes
*/

#include <stdio.h>

/*
* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
* Legal ops: ! ~ & ^| + << >>
*  Max ops: 6
*/
int getByte(int x, int n) {
    // 0xff -> 255
    //Shift 8*n bits to right and generate the bits which are set in first 8 bits
    return (x >> 8*n) & 0xff;
}


int main()
{   int ans, n=1, x=0x12345678;
    ans = getByte(x, n);
    printf("%x", ans);
    return 0;
}