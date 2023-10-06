#include <stdio.h>
#include <omp.h>

void parallelBubbleSort(int arr[], int n) {
    int temp;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        #pragma omp parallel for shared(arr, n) private(temp) reduction(||:swapped)
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; // If no swaps occurred, the array is already sorted.
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    parallelBubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
