#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 25

typedef struct Stack {
    char arr[MAX_SIZE];
    int top;
}Stack;

bool isEmpty(Stack *s){
    return s->top == -1;
}
bool isFull(Stack *s){
    return s->top == MAX_SIZE;
}
void push(Stack *s,int data){
    s->top++;
    s->arr[s->top] = data;
}
void pop(Stack *s){
    s->top--;
}
bool match(char a,char b){
    // if(a == '(' && b == ')'){
    //     return true;
    // }
    // if(a == '[' && b == ']'){
    //     return true;
    // }
    // if(a == '{' && b == '}'){
    //     return true;
    // }
    if(a == '(' && b == ')'  ||  a == '[' && b == ']'  ||  a == '{' && b =='}'){
        return true;
    }
    return false;
}
bool ParenthesisMatch(char *exp){
    Stack *s = malloc(MAX_SIZE*sizeof(char));
    s->top = -1;
    for(int i=0;exp[i] != '\0';i++){
        if(exp[i] == '(' || exp[i] =='[' || exp[i] =='{'){
            push(s,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] =='}'){
            if(isEmpty(s)){
                return false;
            }
            if(match(s->arr[s->top] , exp[i])){
                pop(s);
            }else{
                return false;
            }
        }
    }
    free(s);
    return isEmpty(s);
}
int main(){
    char *exp = "{[(a)+b]}+{({[]c})}";
    if(ParenthesisMatch(exp)){
        printf("Balanced brackets\n");
    }else{
        printf("Not balances brackets\n");
    }
    
}