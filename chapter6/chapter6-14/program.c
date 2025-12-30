#include <stdio.h>
#include <stddef.h>

// Constants
#define LENGTH 10
#define LENGTH_MAX 20

// Function prototype
void unionSet(const int set1[], const int set2[]);
void sortArray(int arr[], size_t length);
void printArray(const int arr[], size_t length);

int main(void) {
    int arr1[LENGTH] = {10, 0, 9, 15, 1, 4, 3, 2, 14, 13};
    int arr2[LENGTH] = {2, 9, 20, 4, 5, 8, 7, 6, 17, 18};

    // Print array sets
    puts("Array set 1:");
    printArray(arr1, LENGTH);
    puts("Array set 2:");
    printArray(arr2, LENGTH);

    // Perform union and print the union array
    unionSet(arr1, arr2);

    return 0;
}

// Function definitions
void unionSet(const int set1[], const int set2[]) {
    size_t idx = 0;
    int tempArr[LENGTH_MAX] = {0};
    int arrUnion[LENGTH_MAX] = {0};

    // Fill temp array with both sets
    for (size_t i = 0; i < LENGTH; i++, idx++) {
        tempArr[idx] = set1[i];
        tempArr[idx+LENGTH] = set2[i];
    }

    // Sort temp array
    sortArray(tempArr, LENGTH_MAX);

    // Fill array with unique elements only
    int pivot = -1;
    idx = 0;
    for (size_t i = 0; i < LENGTH_MAX; i++) {
        if (tempArr[i] != pivot) {
            pivot = tempArr[i];
            arrUnion[idx++] = tempArr[i];
        } else {
            continue;
        }
    }

    // Print the union array
    puts("Union array:");
    printArray(arrUnion, idx);

    return;
}

// This is for combined array only
void sortArray(int arr[], size_t length) {
    // Standard bubble sort
    for (size_t i = 0; i < length - 1; i++)
        for (size_t j = 0; j < length - 1 - i; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

    return;
}

void printArray(const int arr[], size_t length) {
    for (size_t i = 0; i < length; i++)
        printf("%-5d", arr[i]);
    puts("");

    return;
}
