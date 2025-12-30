#include <stdio.h>
#include <stddef.h>

// Constants
#define LENGTH 10
#define LENGTH_MAX 20

// Function prototypes
void intersectSet(const int set1[], const int set2[]);
void printArray(const int arr[], size_t length);
void sortArray(int arr[], size_t length);
void removeDuplicates(const int source[], int dest[], size_t length);

int main(void) {
    int arr1[LENGTH] = {10, 0, 9, 15, 1, 4, 3, 2, 14, 13};
    int arr2[LENGTH] = {2, 9, 20, 4, 5, 8, 7, 6, 17, 18};

    // Print array sets
    puts("Array set 1:");
    printArray(arr1, LENGTH);
    puts("Array set 2:");
    printArray(arr2, LENGTH);

    // Intersect and print
    intersectSet(arr1, arr2);

    return 0;
}

// Function definitions
void intersectSet(const int set1[], const int set2[]) {
    int new_set1[LENGTH] = {0};
    int new_set2[LENGTH] = {0};

    // Clean both arrays
    return;
}

void printArray(const int arr[], size_t length) {
    for (size_t i = 0; i < length; i++)
        printf("%-5d", arr[i]);
    puts("");

    return;
}

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
