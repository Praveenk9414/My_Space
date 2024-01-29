#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

typedef struct queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
} queue;

// Function to check if the queue is empty
int isEmpty(queue *q) {
    return q->rear == q->front;
}

// Function to check if the queue is full
int isFull(queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Function to enqueue (insert) an element into the queue
void enqueue(queue *q, int data) {
    if (isFull(q)) {
        printf("Queue overflow\n");
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->arr[q->rear] = data;
        printf("Enqueued: %d\n", data);
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue(queue *q) {
    int val = -1; // Default value if the queue is empty
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
        val = q->arr[q->front];
    }
    return val;
}

// Function to display the current state of the queue
void display(queue *q) {
    printf("Front: %d\n", q->front);
    printf("Rear: %d\n", q->rear);
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        do {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (q->rear + 1) % MAX_SIZE);
    }
    printf("\n");
}

int main() {
    queue *q = malloc(sizeof(queue));
    q->rear = q->front = 0; // Initialize the circular queue with initial conditions

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("%d removed from queue\n", dequeue(q));
    printf("%d removed from queue\n", dequeue(q));
    printf("%d removed from queue\n", dequeue(q));
    printf("%d removed from queue\n", dequeue(q));

    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);
    enqueue(q, 100);

    display(q);

    // Free the allocated memory
    free(q);

    return 0;
}
