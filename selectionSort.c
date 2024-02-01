#include <stdio.h>

// Function to perform selection sort on an array
void selectionSort(int *arr, int sizeArr) {
    // Outer loop for the passes
    for (int pass = 0; pass <= sizeArr - 1; pass++) {
        // Assume the minimum element is at the current position
        int minIndex = pass;

        // Inner loop to find the minimum element's index in the unsorted part
        for (int i = pass + 1; i < sizeArr; i++) {
            // Compare the current element with the assumed minimum element
            if (arr[i] < arr[minIndex]) {
                // If the current element is smaller, update minIndex
                minIndex = i;
            }
        }

        // Swap the minimum element with the first element in the unsorted part
        int temp = arr[pass];
        arr[pass] = arr[minIndex];
        arr[minIndex] = temp;

        // Display the array after each pass (for visualization)
        printf("Pass %d: ", pass);
        for (int j = 0; j <= sizeArr - 1; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

// Function to display elements of an array
void display(int *arr, int sizeArr) {
    for (int i = 0; i <= sizeArr - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 0, 7, 1, 3};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    // Display the original unsorted array
    printf("Unsorted Array: ");
    display(arr, sizeArr);

    // Sort the array using selection sort
    selectionSort(arr, sizeArr);

    // Display the sorted array
    printf("Sorted Array: ");
    display(arr, sizeArr);

    return 0;
}
