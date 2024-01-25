#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
char pop(Stack *s){
    char popped_value = s->arr[s->top];
    s->top--;
    return popped_value;
}
int isOperator(char opr){
    if(opr =='+' || opr =='-' || opr =='*' || opr =='/'){
        return 1;
    }
    return 0;
}
int precedence(char a){
    if(a == '^'){
        return 3;
    }else if( a == '*' || a == '/'){
        return 2;
    }else if( a == '+' || a == '-'){
        return 1;
    }else{
        return 0;
    }
}
char *infixToPostfix(char * infix){
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    char * postfix = malloc((strlen(infix)+1)*(sizeof(char))); // len of infix +1 --> +1 for '/0' to be stored
    int i=0; // To Scanner the infix Exp
    int j=0; // To fill the postfix Exp
    
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++,j++;
        }else{
            if( precedence(infix[i]) > precedence(s->arr[s->top]) ){
                push(s,infix[i]);
            }else{
                while(s->top != -1){
                    postfix[j] = pop(s);
                    j++;
                }
                push(s,infix[i]);
            }
            i++;
        }
    }
    while(!isEmpty(s)){         // for the remaining operators present in the stack
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    char * infix = "a+b*c-d/e+s+c*d^q"; 
    char *postfix = infixToPostfix(infix);
    int i=0;
    while(postfix[i] !='\0'){
        printf("%c",postfix[i]);
        i++;
    }
    printf("\n");
}