#include <stdio.h>
void Bubble_sort (int array[],int n);
void swap (int *a,int *b);
int main() {

    int n;
    printf("Enter the size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elemnts of the array");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }

    Bubble_sort(arr,n);
    printf("sorted array is ");
    for (int i = 0; i < n ; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}
void Bubble_sort (int array[],int n)
{
    for (int i = 0; i < n-1; ++i) {
        int flag = 0;
        for (int j = 0; j < n-i-1; ++j) {
            if (array[j] > array[j+1])
            {
                swap(&array[j],&array[j+1]);
                flag = 1;
            }
        }
        if (flag==0)
            break;
    }
}
void swap (int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
