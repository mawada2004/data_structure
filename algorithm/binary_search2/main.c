#include <stdio.h>

int Binary_search(int array[], int size, int x);

int main() {
    int array[] = {1, 4, 6, 8, 9, 12};
    int len = sizeof(array) / sizeof(array[0]);
    int x = Binary_search(array, len, 6);
    if (x != -1) {
        printf("Element found at index %d\n", x);
    } else {
        printf("Element not found\n");
    }
    return 0;
}

int Binary_search(int array[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x) {
            return mid;
        } else if (array[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
