#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 15

typedef struct Queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
}Queue;
int isEmpty(Queue *q){
    return q->front == q->rear;
}
int isFull(Queue *q){
    return q->rear == MAX_SIZE-1;
}
void enqueue(Queue *q,int data){
    if(isFull(q)){
        printf("The Queue is Full\n");
    }else{
        q->rear ++;
        q->arr[q->rear] = data;
    }
}
void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("The Queue is Empty... Nothing to be dequeued.\n");
    }else{
        q->front++;
                    // If the front has caught up with the rear, reset the queue
        if(q->front > q->rear){
            q->front = -1;
            q->rear = -1;
        }
    }
}
void display(Queue *q){
    printf("Front :%d\n",q->front);
    printf("Rear :%d\n",q->rear);
    printf("Elements: ");
    for(int i=q->front+1;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
}
void peek(Queue *q,int pos){
    if(pos >= q->front  && pos <= q->rear){
        printf("%d\n",q->arr[pos]);
    }else{
        printf("Invalid Position\n");
    }
}
int main(){
    Queue * q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);

    dequeue(q);
    dequeue(q);

    display(q);
    peek(2);
}