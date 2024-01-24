#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#define MAX_SIZE 10

typedef struct Stack{
    char arr[MAX_SIZE];
    int top;
}Stack;
bool isEmpty(Stack *s){
    return s->top == -1;
}
bool isFull(Stack *s){
    return s->top == MAX_SIZE;
}
void push(Stack *s,char data){
    if(s->top == MAX_SIZE-1){
        printf("Stack is full");
    }
    else{
        s->top++;
        s->arr[s->top] = data;
    }
}
void pop(Stack *s){
    if(s->top == -1){
        printf("Stack is Empty\n");
    }else{
        s->top--;
    }
}
bool parenthesisCheck(char *exp){
    Stack *s = malloc(MAX_SIZE*(sizeof(char)));
    s->top = -1;
    for(int i=0;exp[i] != '\0';i++){
        if(exp[i] == '('){
            push(s,exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(s)){
                return false;
            }
            else{
                pop(s);
            }
        } 
    }
    bool result = isEmpty(s);
    return result;
    free(s);
}
int main(){
    char *exp = "(a+b+(c)";
    if(parenthesisCheck(exp)){
        printf("It is a balenced parenthesis\n");
    }else{
        printf("Not a balanced paranthesis\n");
    }
   
}