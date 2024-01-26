#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 15

// Structure for the circular queue
typedef struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
void enqueue(Queue *q, int data);
void dequeue(Queue *q);
void display(Queue *q);
void peek(Queue *q, int pos);

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

int main() {
    // Initialize the circular queue
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    // Enqueue elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);

    // Dequeue elements from the queue
    dequeue(q);
    dequeue(q);
    dequeue(q);

    // Display the elements in the queue
    display(q);

    // Peek at a specific position in the queue
    peek(q, 4);

    // Free allocated memory
    free(q);

    return 0;
}

// Enqueue operation to insert an element into the queue
void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("The Queue is Full\n");
    } else {
        q->rear++;
        q->arr[q->rear] = data;
    }
}

// Dequeue operation to remove an element from the queue
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("The Queue is Empty... Nothing to be dequeued.\n");
    } else {
        q->front++;
        // If the front has caught up with the rear, reset the queue
        if (q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }
    }
}

// Display the elements in the queue
void display(Queue *q) {
    printf("Front: %d\n", q->front);
    printf("Rear: %d\n", q->rear);
    printf("Elements: ");
    if (isEmpty(q)) {
        printf("The Queue is Empty");
    } else {
        for (int i = q->front + 1; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
    }
    printf("\n");
}

// Peek at a specific position in the queue
void peek(Queue *q, int pos) {
    if (pos >= q->front && pos <= q->rear) {
        printf("Queue at %d position is %d\n", pos, q->arr[pos]);
    } else {
        printf("Invalid Position\n");
    }
}
