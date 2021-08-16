/*
 * Problem-2: find Mth smallest number.
 * Raghav Munjal 1910990074 16/08/21
 * Assignment_8 -> Algorithms
*/

#include <stdio.h>

int swap(int *arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int *arr, int l, int h)
{   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,h);
    return i+1;
}

int MthSmallest(int *arr,int n,int m){
    int l=0,r=n-1;
    while(l<=r){
        int p=partition(arr,l,r);
        if(p==m-1)
            return p;
        else if(p>m-1)
            r=p-1;
        else
            l=p+1;
    }
    return -1;
}
    

int main()
{
    int n,m;

    printf("Enter size of arr: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter Elements: ");
    for(int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);
    
    printf("Enter M : ");
    scanf("%d", &m);
    
    int indx = MthSmallest(arr,n,m);
    
    printf("%d",arr[indx]);
    
    return 0;
}
