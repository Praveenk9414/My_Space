#include <stdio.h> 

// Function to perform counting sort on an array
void countSort(int *arr, int sizeArr) {
    // Find the maximum value in the array
    int max = 0;
    for (int i = 0; i < sizeArr; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create an array to store the count of each element
    int K[max + 1];
    for (int i = 0; i <= max; i++) {
        K[i] = 0;
    }

    // Count the occurrences of each element in the original array
    for (int i = 0; i < sizeArr; i++) {
        K[arr[i]]++;
    }

    // Reconstruct the sorted array based on the count array
    int i = 0;
    int j = 0;
    while (i <= max) {
        if (K[i] > 0) {
            arr[j] = i;
            K[i]--;
            j++;
        } else {
            i++;
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
    // Input array
    int arr[] = {3, 1, 9, 7, 1, 2, 4};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    // Display the original array
    printf("Original Array: ");
    display(arr, sizeArr);

    // Perform counting sort
    countSort(arr, sizeArr);

    // Display the sorted array
    printf("Sorted Array: ");
    display(arr, sizeArr);

    return 0;
}


/*In C, array indices start from 0. When you define an array of size max+1,
    it has valid indices from 0 to max inclusive. 
So, for (int i = 0; i < max+1; i++) iterates from 0 to max, 
    and for (int i = 0; i <= max; i++) also iterates from 0 to max.*/