#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void quickSortArray(int array[], int n) {
    quickSort(array, 0, n - 1);
}

int main() {
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(array) / sizeof(array[0]);

    quickSortArray(array, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}


