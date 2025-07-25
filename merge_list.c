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

// merging unsorted linked list
struct node *merge_unsorted_list(struct node *list1, struct node *list2){

    // handling edge cases
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct node *p = list1;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = list2;
    return list1;
}

// merging sorted linked list
struct node *merge_sorted_list(struct node *list1, struct node *list2){

    // handling edge cases
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct node dummy;
    struct node *temp = &dummy;
    dummy.next = NULL;


    while(list1!=NULL && list2!=NULL){
        if (list1->data < list2->data){
            temp->next = list1;
            list1 = list1->next;
        }else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (list1 == NULL) temp->next = list2;
    else temp->next = list1;
    
    return dummy.next;
}

int main(){
    struct node *list1 = create_node(1);
    struct node *h1 = create_node(2);
    struct node *h2 = create_node(4);

    list1->next = h1;
    h1->next = h2;

    struct node *list2 = create_node(1);
    struct node *h6 = create_node(3);
    struct node *h7 = create_node(4);

    list2->next = h6;
    h6->next = h7;

    // traverse_list(list1);
    // traverse_list(list2);

    // traverse_list(merge_unsorted_list(list1, list2));

    traverse_list(merge_sorted_list(list1, list2));
}