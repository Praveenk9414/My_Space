// incomplete
sdfs

#include <stdio.h>
#include <stdbool.h>


// Given an array of integers nums, return true if there exists any increasing triplet subsequence, i.e., three indices i, j, and k such that:
// i < j < k, and
// nums[i] < nums[j] < nums[k]
// The three elements do not need to be adjacent — only their order in the array must satisfy the condition.
// Otherwise, return false.

bool increasingTriplet(int* nums, int numsSize) {
    int i = 1;
    while (i < numsSize - 1) {
        if (nums[i - 1] < nums[i]){
            int j = i + 1;
            while (j < numsSize){
                if (nums[j] > nums[i]){
                    return true;
                }
                j++;
            }
        }
        i++;
    }
    return false;
}

int main(){
    int arr[] = {5,4,3,2,1};
    // int arr[] = {1,2,3,4,5};
    int numsSize = sizeof(arr)/sizeof(int);
    int *nums = arr; 
    printf("%d\n",increasingTriplet(nums, numsSize));

}