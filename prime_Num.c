#include <stdio.h> 
int primeCheck(int num){
    if(num <2){
        return 0;
    }else{
        for(int a = num/2;a>2;a--){
            if(num%a==0){
                a--;
                return 0;
            }else{
                return 1;
            }
        }
    }
}
int main(){
    printf("Enter the number to check prime Number.\n");
    int num;
    scanf("%d",&num);
    if(primeCheck(num)){
        printf("It is a Prime number\n");
    }else{
        printf("Not a Prime Number\n");
    }
}