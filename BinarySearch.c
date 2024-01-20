#include<stdio.h>

int search(int arr[],int size,int val){
    int mid;
    int low = 0;
    int high = size-1;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==val){
            return mid;
        }
        if(arr[mid]<val){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(int);
    int val;
    scanf("%d",&val);
    int x = search(arr,size,val);
    if(x == -1){
        printf("The number was not found in the array.");
    }
    else{
        printf("Found the number at index:%d\n",x);
    }
}
