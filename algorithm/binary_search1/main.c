#include <stdio.h>
int Binary_search(int array[],int low,int high,int x);
int main() {
    int n;
    printf("Enter the size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elemnts of the sorted array");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    int a;
    printf("enter the element you want to search");
    scanf("%d",&a);

    int found=Binary_search(arr,0,n-1,a);
    printf("%d",found);
    return 0;
}
int Binary_search(int array[],int low,int high,int x)
{
    if (low>high)
        return -1;
    int mid=(low+(high-low))/2;
    if (x==array[mid])
        return mid;
    else if(x>array[mid])
        return Binary_search(array,mid+1,high,x);
    else
        return Binary_search(array,low,mid-1,x);
}