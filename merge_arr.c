#include <stdio.h>

int main(){
    int arr1[] = {1,2,4};
    int arr2[] = {1,3,4};

    int len_arr1 = sizeof(arr1)/ sizeof(int);
    int len_arr2 = sizeof(arr2)/ sizeof(int);

    int len_new_arr = len_arr1 + len_arr2;

    int new_arr[len_new_arr];

    int i=0;
    int j=0;
    int k=0;
    while (i!=len_arr1 || j!=len_arr2){
        if (arr1[i] < arr2[j]){
            new_arr[k] = arr1[i];
            i++;
        }else{
            new_arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    for (int i=0; i<len_new_arr; i++){
        printf("%d\n", new_arr[i]);
    }
}