#include <stdio.h>
#include <stdlib.h>

// defining a node
struct node{
    int data;
    struct node *next;
};

// creating a node
struct node *create_node(int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// traverse list
void traverse_list(struct node *head){
    struct node *p = head;
    do{
        printf("%d\n",p->data);
        p = p->next;
    }while(p != NULL);
}

int main(){
    struct node *head = create_node(1);
    struct node *h1 = create_node(2);
    struct node *h2 = create_node(4);

    head->next = h1;
    h1->next = h2;

    traverse_list(head);
}