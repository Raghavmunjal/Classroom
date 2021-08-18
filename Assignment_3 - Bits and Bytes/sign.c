/*
 * Problem-3: Sign
 * Raghav Munjal 1910990074 12/08/21
 * Assignment_3 -> Bits and Bytes
*/

#include <stdio.h>

/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10
*/
int sign(int x) {
    
    // ~x+1 = -x
   // n<0 x>>31 = -1 ,-x>>31 = 0
   // n>0 x>>31 = 0 , -x>>31 = 1
   // n=0 x>>31 = 0 , -x>>31 = 0

   return  (x >> 31) - (-x >> 31);
}

int main()
{   
    int n,ans;
    printf("Enter Number :");
    scanf("%d",&n);
    ans = sign(n);
    if(ans == 1){
        printf("Positive");
    }else if(ans == 0){
        printf("Zero");
    }else{
        printf("Negative");
    }
    return 0;
}