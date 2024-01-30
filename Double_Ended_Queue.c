#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

typedef struct queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
} queue;

// Function to check if the queue is empty
int isEmpty(queue *q) {
    return q->front == q->rear;
}

// Function to check if the queue is full
int isFull(queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to enqueue at the front of the queue
void enqueueFront(queue *q, int data) {
    if (q->front == -1) {
        printf("The queue is Full.\n");
    } else {
        q->front--;
        q->arr[q->front] = data;
    }
}

// Function to enqueue at the rear of the queue
void enqueueRear(queue *q, int data) {
    if (isFull(q)) {
        printf("The queue is Full.\n");
    } else {
        q->rear++;
        q->arr[q->rear] = data;
    }
}

// Function to dequeue from the front of the queue
int dequeueFront(queue *q) {
    if (isEmpty(q)) {
        printf("The queue is Empty.\n");
        return -1;
    } else {
        q->front++;
        int temp = q->arr[q->front];
        return temp;
    }
}

// Function to dequeue from the rear of the queue
int dequeueRear(queue *q) {
    if (isEmpty(q)) {
        printf("The queue is Empty.\n");
        return -1;
    } else {
        int temp = q->arr[q->rear];
        q->rear--;
        return temp;
    }
}

// Function to display the elements in the queue
void display(queue *q) {
    if (isEmpty(q)) {
        printf("The queue is Empty\n");
    } else {
        printf("Queue elements are :");
        for (int i = q->front + 1; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    // Initializing the double-ended queue
    queue *q = malloc(sizeof(queue));
    q->front = q->rear = -1;

    // Enqueue elements at the rear
    enqueueRear(q, 10);
    enqueueRear(q, 20);
    enqueueRear(q, 30);
    enqueueRear(q, 40);

    // Display the queue
    display(q);

    // Dequeue elements from the front
    printf("removed %d\n", dequeueFront(q));
    printf("removed %d\n", dequeueFront(q));

    // Display the updated queue
    display(q);

    // Enqueue elements at the front
    enqueueFront(q, 10);
    enqueueFront(q, 20);

    // Display the updated queue
    display(q);

    // Dequeue elements from the rear
    printf("removed %d\n", dequeueRear(q));
    printf("removed %d\n", dequeueRear(q));

    // Display the final queue
    display(q);

    // Free allocated memory
    free(q);
}
