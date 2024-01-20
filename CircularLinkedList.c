#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
void TraverseList(node *head) {
    node *p = head;
    do{
        printf("%d\n", p->data);
        p = p->next;
    }while(p != head);
}
node *Create_Node(int data){
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
node *InsertAtHead(node *FirstNode,int data){
    node* NewNode = Create_Node(data);
    node *ptr = FirstNode;
    while(ptr->next != FirstNode){
        ptr = ptr->next;
    }
    ptr->next = NewNode;
    node *temp = FirstNode;
    FirstNode = NewNode;
    NewNode->next = temp;
    return FirstNode;
}
node *InsertAtAnyIndex(node *FirstNode,int index,int data){
    node *NewNode = malloc(sizeof(node));
    NewNode->data = data;
    node *ptr = FirstNode;
    int count = 0;
    while(ptr->next != FirstNode){
        count ++;
        if(count == index){
            break;
        }
        ptr = ptr->next;
    }
    node *temp = ptr->next;
    ptr->next = NewNode;
    NewNode->next = temp;
    return FirstNode;
}
node *InsertAtEnd(node *FirstNode,int data){
    node *NewNode = malloc(sizeof(node));
    NewNode->data = data;
    node *ptr = FirstNode;
    while(ptr->next != FirstNode){
        ptr = ptr->next;
    }
    ptr->next = NewNode;
    NewNode->next = FirstNode;
    return FirstNode;
}
node *RmFromHead(node *FirstNode){
    node *p = FirstNode->next;
    node *q = FirstNode;
    while(q->next != FirstNode){
        q = q->next;
    }
    q->next = p;
    free(FirstNode);
    return p;
}
node *RmFromAnyIndex(node *FirstNode,int index){
    node *ptr = FirstNode;
    int count =0;
    node *q;
    while(ptr->next != FirstNode){
        count ++;
        q = ptr->next;
        if(count == index){
            break;
        }
        ptr = ptr->next;
    }
    ptr->next = q->next;
    free(q);
    return FirstNode;
}
node *RmFromEnd(node *FirstNode){
    node *p = FirstNode;
    node *q = FirstNode->next;
    while(q->next != FirstNode){
        p = p->next;
        q = q->next;
    }
    p->next = q->next; // or p->next = FirstNode;
    free(q);
    return FirstNode;
}
int main(){
    node *head = Create_Node(-1); // Just a pointer node which points to the first node.
    node *H1 = Create_Node(23);
    node *H2 = Create_Node(99);
    node *H3 = Create_Node(76);
    node *H4 = Create_Node(34);

    head->next = H1;
    H1->next  = H2;
    H2->next  = H3;
    H3->next  = H4;
    H4->next  = H1;

    TraverseList(head->next);

    head->next = InsertAtHead(head->next,11);
    printf("\n");
    TraverseList(head->next);

    head->next = InsertAtAnyIndex(head->next,2,10);
    printf("\n");
    TraverseList(head->next);    

    head->next = InsertAtEnd(head->next,101);
    printf("\n");
    TraverseList(head->next);

    head->next = RmFromHead(head->next);
    printf("\n");
    TraverseList(head->next);

    head->next = RmFromAnyIndex(head->next,3);
    printf("\n");
    TraverseList(head->next);

    head->next = RmFromEnd(head->next);
    printf("\n");
    TraverseList(head->next);
}
