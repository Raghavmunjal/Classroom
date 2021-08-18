/*
 * Problem-6: Conditional
 * Raghav Munjal 1910990074 16/08/21
 * Assignment_3 -> Bits and Bytes
*/

#include <stdio.h>

/*
* conditional - same as x ? y : z
* example conditional (2, 4, 5) = 4
* ! ~ & ^ | + << >>
* Max ops: 16
*/

int conditional(int x, int y, int z) {
    x = ~!!x + 1;
    return (x & y) | (~x & z);
}

int main()
{   
    int x;
    scanf("%d", &x);
    int y;
    scanf("%d",&y);
    int z;
    scanf("%d",&z);
    printf("%d",conditional(x,y,z));
    return 0;
}