#include<stdio.h>

// Function to search for a value in a sorted array 
int search(int arr[], int size, int val) {
    // Check if the array is sorted
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            printf("The Array is not sorted\n");
            return -1;
        }
    }

    int middle;
    int lowIndex = 0;
    int highIndex = size - 1;

    // Binary search
    while (lowIndex <= highIndex) {
        middle = (lowIndex + highIndex) / 2;

        if (arr[middle] == val) {
            return middle; // Element found
        }

        if (arr[middle] < val) {
            lowIndex = middle + 1;
        } else {
            highIndex = middle - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int val;
    printf("Enter the number to search: ");
    scanf("%d", &val);

    int index = search(arr, size, val);

    if (index == -1) {
        printf("The number was not found in the array.\n");
    } else {
        printf("Found the number at index: %d\n", index);
    }

    return 0;
}
