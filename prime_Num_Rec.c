#include <stdio.h> 
int PrimeCheck(int num , int a){
    if(num<2){
        return 0;
    }
    if(num == 2 || a == 1){
        return 1;
    }
    if(num%a==0){
        return 0;
    }else{
        return PrimeCheck(num,a-1);
    }
    return 1;
}
int main(){
    printf("Enter the number to check whether prime Number :\n");
    int num;
    scanf("%d",&num);
    if(PrimeCheck(num,num/2)){
        printf("It is a Prime number\n");
    }else{
        printf("Not a Prime Number\n");
    }
}