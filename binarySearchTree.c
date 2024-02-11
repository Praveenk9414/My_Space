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

// Function for in-order traversal
void InOrder(node *ptr) {
    if (ptr != NULL) {
        InOrder(ptr->leftNode);
        printf("%d ", ptr->data);
        InOrder(ptr->rightNode);
    }
}
int isBST(node *ptr){
    static node *prev = NULL;
    if(ptr != NULL){
        if(!isBST(ptr->leftNode)){
            return 0;
        }
        if(prev != NULL && ptr->data <= prev->data){
            return 0;
        }
        prev = ptr;
        return isBST(ptr->rightNode);
    }else{
        return 1;
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

    printf("In-order traversal: ");
    InOrder(H1);
    printf("\n");
    if(isBST(H1) == 1){
        printf("Yes it is inorder\n");
    }else{
        printf("No it is not inorder\n");
    }

    return 0;
}
