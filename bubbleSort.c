#include <stdio.h>

// Function to perform bubble sort on an array
void bubbleSort(int *arr, int sizeArr) {
    // Outer loop for the number of passes
    int isSorted = 0; // Flag to check if the array is already sorted

    for (int pass = 0; pass < sizeArr - 1; pass++) {
        // Inner loop for each pass
        // (sizeArr - pass - 1) ensures that we don't compare/sort elements that are already in their correct positions
        printf("Working on pass %d\n", pass + 1);
        isSorted = 1; // Assume the array is sorted

        for (int i = 0; i < sizeArr - pass - 1; i++) {
            // Compare adjacent elements and swap if they are in the wrong order
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = 0; // If a swap occurs, the array is not sorted
            }
        }

        // If the array is already sorted, no need to continue the outer loop
        if (isSorted == 1) {
            return;
        }
    }
}

// Function to display elements of an array
void display(int *arr, int sizeArr) {
    for (int i = 0; i < sizeArr; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // int arr[] = {1, 7, 3, 5, 2};
    int arr[] = {3, 3, 3, 4};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    // Create a copy of the array for sorting
    int sortedArr[sizeArr];
    for (int i = 0; i < sizeArr; i++) {
        sortedArr[i] = arr[i];
    }

    // Sort the array using bubble sort
    bubbleSort(sortedArr, sizeArr);

    // Display the original and sorted arrays
    printf("Original array: ");
    display(arr, sizeArr);

    printf("Sorted array: ");
    display(sortedArr, sizeArr);

    return 0;
}
