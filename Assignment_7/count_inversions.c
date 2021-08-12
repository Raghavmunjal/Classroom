/*
 * Problem-1: Inversion Count for an Array
 * Raghav Munjal 1910990074 12/08/21
 * Assignment_7 -> Sorting Algos
*/

#include <stdio.h>
#include <stdlib.h>

int countAndMerge(int *arr, int l, int m, int r)
{
    int n1=m-l+1, n2=r-m;
    
    int left[n1];
    int right[n2];
    
    for(int i=0;i<n1;i++)
        left[i] = arr[i+l];
    for(int j=0;j<n2;j++)
        right[j] = arr[m+1+j]; 
        
    int res=0,i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            {arr[k++] = left[i++];}
        else{
            arr[k++] = right[j++];
            res=res+(n1-i);
        }
    }
    while(i<n1)
        arr[k++] = left[i++];
    while(j<n2)
        arr[k++] = right[j++];
        
    return res;
}


int countInv(int *arr, int l, int r){

    int res = 0;
    if (l<r) {
           
        int m = (r + l) / 2;
     
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += countAndMerge(arr, l, m , r);
    }
    
    return res;

}

int main()
{
    int n, count = 0;


    printf("Enter size of arr: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter Elements: ");
    for(int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    int ans = countInv(arr, 0, n-1);

    printf("\nInversion count = %d",ans);

    return 0;
}