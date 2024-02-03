#include <stdio.h> 

// Function to perform merging of two sorted subarrays
void Merge(int *A, int mid, int low, int high);

// Function to perform merge sort on the array
void mergeSort(int *A, int low, int high);

// Function to display elements of an array
void display(int *A, int sizeA);

int main(){
    // Initialize the array
    int A[] = {7, 9, 18, 19, 22, 1, 6, 9, 11};
    int sizeA = sizeof(A) / sizeof(A[0]);

    // Display the original array
    printf("Original Array: ");
    display(A, sizeA);

    // Perform merge sort on the array
    mergeSort(A, 0, sizeA - 1);

    // Display the sorted array
    printf("Sorted Array: ");
    display(A, sizeA);

    return 0;
}

// Function to display elements of an array
void display(int *A, int sizeA){
    for(int i = 0; i < sizeA; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Function to perform merging of two sorted subarrays
void Merge(int *A, int mid, int low, int high){
    int i = low;
    int j = mid + 1;   // Initialize indices for the two subarrays
    int k = low;       // Initialize index for the merged array

    int K[high + 1];    // Temporary array to store merged elements
    while(i <= mid && j <= high){
        // Compare elements from the two subarrays and merge them in sorted order
        if(A[i] < A[j]){
            K[k] = A[i];
            i++;
        }else{
            K[k] = A[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements from the first subarray, if any
    while(i <= mid){
        K[k] = A[i];
        i++; k++;
    }

    // Copy the remaining elements from the second subarray, if any
    while(j <= high){
        K[k] = A[j];
        j++; k++;
    }

    // Copy the merged elements back to the original array
    for(int i = low; i <= high; i++){
        A[i] = K[i];
    }

    // Display the current state of the array after each merge pass
    printf("Merge Pass:");
    display(A, high + 1);
}

// Function to perform merge sort on the array
void mergeSort(int *A, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;   // Calculate the middle index
        mergeSort(A, low, mid);       // Recursively sort the first half
        mergeSort(A, mid + 1, high);  // Recursively sort the second half
        Merge(A, mid, low, high);     // Merge the sorted halves
    }
}
