// incomplete
sdfs

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    for (int i=0; i<numsSize; i++){
        if (nums[i] == 0){
            int j = i;
            while(j<numsSize){
                if (nums[j]==0){
                    j++;
                }else{
                    break;
                }
            }
            // int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = 0;
        }
    }
}

int main(){
    int arr[] = {0,1,0,3,12};
    int numsSize = sizeof(arr)/ sizeof(int);
    int *p = arr;
    moveZeroes(p, numsSize);
    for (int i=0; i<numsSize; i++){
        printf("%d-",arr[i]);
    }
}