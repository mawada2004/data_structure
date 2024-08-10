#include <stdio.h>
#include <stdlib.h>

void Merge(int arr1[], int n1, int arr2[], int n2, int merged_array[]);
void mergeSort(int array[], int n);

int main() {
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(array) / sizeof(array[0]);

    mergeSort(array, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void Merge(int arr1[], int n1, int arr2[], int n2, int merged_array[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged_array[k++] = arr1[i++];
        } else {
            merged_array[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        merged_array[k++] = arr1[i++];
    }
    while (j < n2) {
        merged_array[k++] = arr2[j++];
    }
}

void mergeSort(int array[], int n) {
    if (n < 2) return;

    int mid = n / 2;

    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((n - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = array[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    Merge(left, mid, right, n - mid, array);

    free(left);
    free(right);
}
