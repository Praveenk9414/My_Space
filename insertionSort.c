#include <stdio.h> 

// Function to perform insertion sort on an array
void insertionSort(int *arr, int sizeArr) {
    // Outer loop iterates over each element in the array starting from the second element.
    for (int pass = 1; pass <= sizeArr; pass++) {
        // Store the current element to be inserted into the sorted part.
        int currentElement = arr[pass];
        int i;

        // Inner loop iterates over the elements in the sorted part,
        // shifting them to the right until the correct position for the currentElement is found.
        for (i = pass - 1; i >= 0 && arr[i] > currentElement; i--) {
            arr[i + 1] = arr[i];
        }

        // Insert the currentElement into its correct position in the sorted part.
        arr[i + 1] = currentElement;

        // Display the array after each pass (optional, for visualization).
        printf("Pass %d: ", pass);
        for (int j = 0; j < sizeArr; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
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
    int arr[] = {8, 4, 1, 5, 9, 2};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    display(arr, sizeArr);

    // Sort the array using insertion sort
    insertionSort(arr, sizeArr);

    printf("Sorted Array: ");
    display(arr, sizeArr);

    return 0;
}
