#include<stdio.h>
#include<stdlib.h>

// Node structure to represent individual elements in the linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Queue structure to represent the overall queue
typedef struct queue {
    node *front;
    node *rear;
} queue;

// Function to check if the queue is empty
int isEmpty(queue *q) {
    return q->front == NULL;
}

// Function to initialize an empty queue
queue *InitialQueue() {
    queue *q = malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to create a new node with the given data
node *createNode(int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue a new element into the queue
void enqueue(queue *q, int data) {
    node *newNode = createNode(data);
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("The queue is Empty\n");
        return -1; // Return -1 to indicate an empty queue
    } else {
        node *temp = q->front;
        int val = temp->data;
        q->front = temp->next;
        free(temp);
        return val;
    }
}

// Function to display the elements in the queue
void display(queue *q) {
    if (isEmpty(q)) {
        printf("The queue is Empty.\n");
    } else {
        node *ptr = q->front;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    // Initialize an empty queue
    queue *q = InitialQueue();

    // Enqueue some elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Display the elements in the queue
    display(q);

    // Dequeue two elements from the queue
    printf("Removed %d\n", dequeue(q));
    printf("Removed %d\n", dequeue(q));

    // Display the updated elements in the queue
    display(q);

    // Free the memory allocated for the queue structure
    free(q);

    return 0;
}
