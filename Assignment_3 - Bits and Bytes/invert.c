/*
 * Problem-8: Invert
 * Raghav Munjal 1910990074 16/08/21
 * Assignment_3 -> Bits and Bytes
*/
#include <stdio.h>

/*
* Return x with the n bits that begin at position p inverted (i.e. turn 0
* into 1 and vice versa)
* and the rest left unchanged. Consider the indices of x to begin with the
* lower -order bit   numbered
* Legal ops: ~ & ^ | << >>
* as zero
*/
int invert (int x, int p, int n) {
    int val;
    val = ~(~0<<n)<<p-1;
    return val^x;

}

int main()
{   
    int res, x = 26, p = 3, n = 2;
    res = invert(x, p, n);
    printf("%d ",res);
    return 0;
}