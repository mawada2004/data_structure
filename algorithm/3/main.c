#include <stdio.h>
void update (int array[],int n,int index);
int main() {
    int n;
    int index;
    printf("enter no of elements");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements of array");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }

    printf("enter the position to delete\n");
    scanf("%d",&index);

    if (index < 0 || index >= n) {
        printf("Invalid index\n");
        return 1;
    }

    update(arr,n,index);
    return 0;
}
void update (int array[],int n,int index)
{

    for (int i = index; i < n - 1; ++i) {
        array[i] = array[i + 1];
    }

     for (int i = 0; i < n - 1; ++i) {
        printf("%d ", array[i]);
    }
}