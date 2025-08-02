// incomplete
dfs
#include <stdio.h>

int main(){

    // int arr[] = {1,2,3,4};
    int arr[] = {-1,1,0,-3,3};
    int len = sizeof(arr)/sizeof(int);
    int p=1;
    int q=1;
    int arr1[len];
    for (int i=0; i<len; i++){
        p = p*arr[i];
        arr1[i] = p;
    }
    for (int i=0; i<len; i++){
        q = q*arr[len-i-1];
        
    }
}