#include <stdio.h> 

// Function to swap two elements in the array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform the QuickSort algorithm on an array
void quickSort(int *arr, int low, int high){
    // Base case: If the partition size is 1 or less, the array is already sorted
    if(low >= high){
        return;
    }

    // Initialize indices for the partitioning
    int s = low;
    int e = high;

    // Choose a pivot element (in this case, the middle element)
    int mid = (s + e) / 2; // or mid = s + (e - s) / 2
    int pivot = arr[mid];

    // Partition the array around the pivot
    while(s <= e){
        while(arr[s] < pivot){
            s++;
        }
        while(arr[e] > pivot){
            e--;
        }
        if(s <= e){
            // Swap elements to move smaller elements to the left and larger elements to the right
            swap(&arr[s], &arr[e]);
            s++;
            e--;
        }
    }

    // Recursively apply QuickSort to the left and right partitions
    quickSort(arr, low, e);
    quickSort(arr, s, high);
}

// Function to display elements of an array
void display(int *arr, int sizeArr){
    for(int i = 0; i <= sizeArr - 1; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {10, 16, 8, 12, 1, 6, 3, 9, 5};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    // Display the original array
    printf("Unsorted Array: ");
    display(arr, sizeArr);

    // Apply QuickSort to the entire array
    quickSort(arr, 0, sizeArr - 1);

    // Display the sorted array
    printf("Sorted Array: ");
    display(arr, sizeArr);

    return 0;
}
