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
    int arr1[LENGTH] = {10, 0, 9, 15, 1, 4, 1, 2, 14, 13};
    int arr2[LENGTH] = {2, 9, 20, 4, 5, 8, 7, 1, 17, 18};

    // Print array sets
    puts("Array set 1:");
    printArray(arr1, LENGTH);
    puts("Array set 2:");
    printArray(arr2, LENGTH);

    // Sort original arrays
    sortArray(arr1, LENGTH);
    puts("Sorted array 1");
    printArray(arr1, LENGTH);
    sortArray(arr2, LENGTH);
    puts("Sorted array 2");
    printArray(arr2, LENGTH);
    // Intersect and print
    intersectSet(arr1, arr2);

    return 0;
}

// Function definitions
void intersectSet(const int set1[], const int set2[]) {
    int new_set1[LENGTH+1] = {0};
    int new_set2[LENGTH+1] = {0};

    // Clean both arrays
    removeDuplicates(set1, new_set1, LENGTH);
    removeDuplicates(set2, new_set2, LENGTH);

    // Initiate new arrays
    size_t totalElements = new_set1[LENGTH] + new_set2[LENGTH]; // Get total elements from new set 1 and 2 after duplicate removal
    int tempArr[totalElements];
    int arrIntersect[totalElements];

    // Fill temp array with both array sets
    size_t idx = 0;
    for (size_t i = 0; i < (size_t)new_set1[LENGTH]; i++) // new_set1[LENGTH] = set 1 element count after duplicates removal
        tempArr[idx++] = new_set1[i];

    for (size_t i = 0; i < (size_t)new_set2[LENGTH]; i++) // new_set2[LENGTH] = set 2 element count after duplicates removal
        tempArr[idx++] = new_set2[i];

    // sort temp array
    sortArray(tempArr, totalElements);

    // Find duplicates in temp array as the unique object for intersection
    int pivot = -1;
    idx = 0;
    for (size_t i = 0; i < totalElements; i++) {
        if (tempArr[i] != pivot)
            pivot = tempArr[i];
        else // element repetition, put into intersect set
            arrIntersect[idx++] = tempArr[i];
    }

    // Print intersection sets
    puts("Intersection Sets:");
    printArray(arrIntersect, idx);

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

void removeDuplicates(const int source[], int dest[], size_t length) {
    int pivot = -1;
    size_t idx = 0;

    for (size_t i = 0; i < length; i++) {
        if (source[i] != pivot) {
            pivot = source[i];
            dest[idx++] = source[i];
        }
    }

    // Store total array element in the last index
    dest[length] = idx;

    return;
}
