/**
* Program to find the square root of number upto p decimal places using binary search
*
* @Raghav and 1910990074 18/07/2021
* Assignment -> Day1_Coding_Assignment
* Resources -> (https://www.geeksforgeeks.org/find-square-root-number-upto-given-precision-using-binary-search/)
*/


import java.util.Scanner;

public class SqrtWithBinarySearch {
    public static void main(String[] args) {

        Scanner ref = new Scanner(System.in);

        /* Taking Input 
           n is  number and p is precision */
        int n = ref.nextInt();
        int p = ref.nextInt();

        /* Calculating Integral Part of Square root of number */
        int low=1;
        int high=n;
        double result=-1;
        while(low<=high){

            int mid = (low+high)/2;
            int midSq=mid*mid;

            if(midSq==mid){
                result=mid;
                break;
            }
            /* Decrement high if Result lies on the left Side of mid */
            else if(midSq>mid){
                high=mid-1;
            }
            /* Increment low if Result lies on the left Side of mid */
            else{
                result=mid;
                low=mid+1;
            }

        }
        
        /*  For computing the fractional part
		    of square root upto given precision */
        double increment = 0.1;
        for (int i = 0; i < p; i++) {

            while (result * result <= n) {
                result += increment;
            }
            result = result - increment;
            increment = increment / 10;
        }

        /* Printing the result */
        System.out.println((float)result);

        ref.close();
    }
}
