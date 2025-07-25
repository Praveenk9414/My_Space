#include <stdio.h>
#include <stdlib.h>

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

struct node {
    int data;
    struct node *next;
};

void TraverseNode(struct node *head){
    struct node *p = head;
    while(p!=NULL){
        if (p->next==NULL){
            printf("%d\n", p->data);
        }else{
            printf("%d -> ",p->data);
        }
        p = p->next;
    }
}

struct node *CreateNode(int n){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

struct node *CreateLinkList(){
    int num;
    printf("Enter the length of your linked list: ");
    scanf("%d",&num);

    struct node dummy;
    struct node *temp = &dummy;
    dummy.next = NULL;

    for (int i=0; i<num; i++){
        int val;
        printf("Enter node %d: ", i);
        scanf("%d", &val);
        temp->next = CreateNode(val);
        temp = temp->next;
    }
    return dummy.next;
}

struct node *RemKthElement(struct node *head, int k){

    struct node dummy;
    struct node *p = &dummy;
    dummy.next = NULL;

    p->next = head;
    struct node *temp = head;
    int count = 0;
    while(temp!=NULL){
        count ++;
        temp = temp->next;
    }

    int n = count - k+1;
    int len = 0;
    while(p!=NULL){
        len ++;
        if (len == n && p->next !=NULL){
            p->next = p->next->next;
            break;
        }
        p = p->next;
    }
    return dummy.next;
}

int main(){

    struct node *head = CreateLinkList();
    TraverseNode(RemKthElement(head, 1));
    return 0;
}