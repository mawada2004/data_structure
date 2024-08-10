#include <stdio.h>
void Merge_sort (int arr1[],int n1,int arr2[],int n2,int merged_array[]);
int main() {
    int size1, size2;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);
    int arr1[size1];

    printf("Input first array elements: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);
    int arr2[size2];

    printf("Input second array elements: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];

    Merge_sort(arr1, size1, arr2, size2, mergedArray);

    printf("Merged array in ascending order: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedArray[i]);
    }

    return 0;
}
void Merge_sort (int arr1[],int n1,int arr2[],int n2,int merged_array[])
{
    int i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
        if (arr1[i]<=arr2[j])
        {
            merged_array[k++]=arr1[i++];
        }
        else
        {
            merged_array[k++]=arr2[j++];
        }
    }
    while(i<n1)
    {
        merged_array[k++]=arr2[i++];
    }
    while(j<n2)
    {
        merged_array[k++]=arr2[j++];
    }
}