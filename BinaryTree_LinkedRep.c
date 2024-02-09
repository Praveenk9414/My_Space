#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct node {
    int data;
    struct node *leftNode;
    struct node *rightNode;
} node;

// Function to create a new node with the given data
node *createNode(int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;
}

// Function for pre-order traversal
void PreOrder(node *ptr) {
    if (ptr != NULL) {
        printf("%d ", ptr->data);
        PreOrder(ptr->leftNode);
        PreOrder(ptr->rightNode);
    }
}

// Function for in-order traversal
void InOrder(node *ptr) {
    if (ptr != NULL) {
        InOrder(ptr->leftNode);
        printf("%d ", ptr->data);
        InOrder(ptr->rightNode);
    }
}

// Function for post-order traversal
void PostOrder(node *ptr) {
    if (ptr != NULL) {
        PostOrder(ptr->leftNode);
        PostOrder(ptr->rightNode);
        printf("%d ", ptr->data);
    }
}

int main() {
    // Create nodes for the binary tree
    node *H1 = createNode(10);
    node *H2 = createNode(6);
    node *H3 = createNode(15);
    node *H4 = createNode(4);
    node *H5 = createNode(8);
    node *H6 = createNode(11);
    node *H7 = createNode(16);

    // Connect the nodes to form the binary tree structure
    H1->leftNode = H2;
    H1->rightNode = H3;
    H2->leftNode = H4;
    H2->rightNode = H5;
    H3->leftNode = H6;
    H3->rightNode = H7;

    // Perform different types of tree traversals
    printf("Pre-order traversal: ");
    PreOrder(H1);
    printf("\n");

    printf("In-order traversal: ");
    InOrder(H1);
    printf("\n");

    printf("Post-order traversal: ");
    PostOrder(H1);
    printf("\n");

    return 0;
}
