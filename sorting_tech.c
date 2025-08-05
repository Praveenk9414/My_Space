// Sorting Techniques .... at your service

#include <stdio.h>
#include <time.h>

// Bubble SORT -> worst_case complex -> O(n^2)
// Selection Sort works by repeatedly selecting the smallest (or largest) element from the unsorted part and moving it to the beginning.
void bubble_sort(int arr[], int len){
    for (int i=0; i<len-1; i++){
        int swapped = 0;
        for (int j=0; j<len-i-1; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0){
            break;
        }
    }
}

// Selection SORT -> O(n^2)
// Selection sort divides the array into a sorted and an unsorted part. It repeatedly selects the minimum element from the unsorted part and moves it to the beginning

void selection_sort(int arr[], int len){
    for (int i=0; i<len-1; i++){
        int min_indx=i;
        for(int j=i+1; j<len; j++){
            if (arr[j] < arr[min_indx]){
                min_indx = j;
            }
        }
        if (min_indx !=i){
            int temp = arr[i];
            arr[i] = arr[min_indx];
            arr[min_indx] = temp; 
        }
    }
}

// Insertion SORT -> O(n^2)
// Like sorting playing cards in your hand — insert each new element into its correct position among the already sorted ones.
// How It Works (Example for [4, 3, 2, 1]):
    // Start with the second element: 3
    // Compare it with 4, shift 4 to the right → insert 3 before 4
    // 1st iteration -> [4],(3),2,1   -->     (4,3),2,1     --> 3,4,2,1
    // 2nd iteration -> [3,4],(2),1   -->     3,(4,2),1     --> (3,2),4,1    --> 2,3,4,1
    // 3rd iteration -> [2,3,4],(1)   -->     2,3,(4,1)     --> 2,(3,1),4    --> (2,1),3,4   --> 1,2,3,4 
void insertion_sort(int arr[], int len){
    for(int i=0; i<len-1; i++){
        int j=i+1;

        // this while and if cond both can be combined to for a single cond ... then no break needed
        while(j>0){
            if (arr[j-1] > arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }else{
                break;
            }
            j--;
        }
    }
}  

/*
===============================
 Rule of Thumb: Midpoint Calculation
===============================

Always compute mid as:
    int mid = l + (r - l) / 2;

-> Reason:
   Prevents integer overflow that may occur in:
      (l + r) / 2

-> Why it matters:
  If l and r are large (e.g., 2,000,000,000),
  then (l + r) can exceed INT_MAX (2,147,483,647)
  and give wrong results.

-> Safe and standard practice for:
- Merge Sort
- Binary Search
- Any divide-and-conquer algorithm

===============================
*/


void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1; // size of left half
    int n2 = r-m;   // size of right half
    int L[n1], R[n2];

    for (int i=0; i<n1; i++){
        L[i] = arr[i+l];
    }
    for (int i=0; i<n2; i++){
        R[i] = arr[i+m+1];
    }

    int k=l;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if (L[i]<R[j]){
            arr[k] = L[i];
            i++;
            k++;
        }else{
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){

    clock_t start,end;
    double cpu_time_used;

    int arr[] = {12, 11, 13, 5, 6, -3, 0, 11};
    // int arr[] = {3,1,3,4,3};
    int len = sizeof(arr)/sizeof(int);

    start = clock();
    // bubble_sort(arr, len);
    // insertion_sort(arr, len);
    mergeSort(arr, 0, len-1);
    end = clock();

    //now now this cpu_time_used might vary depending on the cpu uptilization ... so usually taken the avg of serious of iteration of this
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    for (int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %f seconds\n", cpu_time_used);

}