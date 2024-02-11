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
    node *newNode = malloc(sizeof(node));  // Allocate memory for the new node
    newNode->data = data;  // Set the data of the new node
    newNode->leftNode = NULL;  // Initialize left child pointer to NULL
    newNode->rightNode = NULL;  // Initialize right child pointer to NULL
    return newNode;  // Return the newly created node
}

// Function for in-order traversal of the binary tree
void InOrder(node *ptr) {
    if (ptr != NULL) {  // Check if the current node is not NULL
        InOrder(ptr->leftNode);  // Recursively traverse the left subtree
        printf("%d ", ptr->data);  // Print the data of the current node
        InOrder(ptr->rightNode);  // Recursively traverse the right subtree
    }
}

// Function to check if a binary tree is a binary search tree (BST)
int isBST(node *ptr) {
    static node *prev = NULL;  // Static variable to store the previous node during traversal
    if (ptr != NULL) {  // Check if the current node is not NULL
        if (!isBST(ptr->leftNode)) {  // Recursively check the left subtree
            return 0;  // Return 0 if the left subtree is not a BST
        }
        if (prev != NULL && ptr->data <= prev->data) {  // Check if the current node violates the BST property
            return 0;  // Return 0 if the BST property is violated
        }
        prev = ptr;  // Update the previous node
        return isBST(ptr->rightNode);  // Recursively check the right subtree
    } else {
        return 1;  // Return 1 if the subtree is empty (i.e., it is a BST)
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

    // Perform in-order traversal of the binary tree
    printf("In-order traversal: ");
    InOrder(H1);
    printf("\n");

    // Check if the binary tree is a BST
    if (isBST(H1) == 1) {
        printf("Yes, it is a binary search tree (BST).\n");
    } else {
        printf("No, it is not a binary search tree (BST).\n");
    }

    return 0;
}
