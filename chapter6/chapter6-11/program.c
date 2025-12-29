#include <stddef.h>
#include <stdio.h>

// Constants
#define SIZE 10

// Function prototypes
void selectionSort(int arr[], size_t size);
void printArray(const int arr[], size_t size);

int main(void) {
    int arr[SIZE] = {14, 19, 3, 10, 1, 5, 20, 13, 13, 9};

    // Print previous array before sorting
    puts("Previous array:");
    printArray(arr, SIZE);

    // Sort the array
    selectionSort(arr, SIZE);

    // Print array after sorting
    puts("Array after sorting:");
    printArray(arr, SIZE);

    return 0;
}

// Function definitions
void selectionSort(int arr[], size_t size) {
    for (size_t i = 0; i < size-1; i++) {
        size_t idx = i;
        for (size_t j = i+1; j < size; j++)
            if (arr[j] < arr[idx])
                idx = j;

        // Swap
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }

    return;
}

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%-4d", arr[i]);
    }
    puts("");

    return;
}
