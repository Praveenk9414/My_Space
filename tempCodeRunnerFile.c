#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct Stack {
    char arr[MAX_SIZE];
    int top;
} Stack;

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char data) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->arr[s->top] = data;
    }
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
    } else {
        s->top--;
    }
}

bool parenthesisCheck(char *exp) {
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(s, exp[i]);
        } else if (exp[i] == ')') {
            if (isEmpty(s)) {
                free(s);
                return false;
            } else {
                pop(s);
            }
        }
    }

    bool result = isEmpty(s);
    free(s);
    return result;
}

int main() {
    char *exp = "(a+b)+c)(";

    if (parenthesisCheck(exp)) {
        printf("It is a balanced parenthesis\n");
    } else {
        printf("Not a balanced parenthesis\n");
    }

    return 0;
}
