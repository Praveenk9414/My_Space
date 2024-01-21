#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

typedef struct Stack{
    int arr[MAX_SIZE];
    int top;
}Stack;

int isEmpty(Stack *s){
    return s->top == -1;
}

int isFull(Stack *s){
    return s->top == MAX_SIZE-1;
}
void push(Stack *s,int data){
    if(s->top == MAX_SIZE-1){
        printf("Stack is Full\n");
    }else{
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
void Display(Stack *s){
    for(int i=0;i<=s->top;i++){
        printf("%d\n",s->arr[i]);
    }
}
int peek(Stack *s,int i){
    int peekIndex = (s->top)-i+1;
    if(peekIndex<0){
        printf("Invalid position of 'i'\n");
    }else{
        printf("value at position %d is :%d\n",i,s->arr[peekIndex]);
    }
}
int main(){
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    
    // if(isEmpty(s)){
    //     printf("Stack is Empty\n");
    // }else{
    //     printf("Stack is Not Empty\n");
    // }

    // if(isFull(s)){
    //     printf("Satck is Full\n");
    // }else{
    //     printf("Stack is not Full\n");
    // }
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    push(s,10);
    push(s,11);
    Display(s);

    printf("\n");
    pop(s);

    Display(s);
    printf("\n");
    peek(s,4);

    return 0;
}