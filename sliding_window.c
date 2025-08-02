// Sliding Window -> 
// You only need to calculate the first window sum fully, 
// and then slide the window by subtracting the element that goes out and adding the new one coming in.

#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    int len = numsSize-k+1;
    double sum = 0;
    for (int i=0; i<k; i++){
        sum +=nums[i];
    }
    double max = sum/k;
    for (int i=k; i<numsSize; i++){
        sum = sum + nums[i] - nums[i-k];
        if (sum/k > max){
            max = sum/k;
        }
    }
    return max;
}

int main(){
    int arr[] = {1,12,-5,-6,50,3};
    int numsSize = sizeof(arr)/sizeof(int);
    int k = 4;
    int *p = arr;
    printf("%f\n",findMaxAverage(p, numsSize, k));
}