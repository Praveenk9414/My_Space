#include <stdio.h>
#include <stdlib.h>

// 342 + 465 = 807
// in linked list 2 -> 4 -> 3 
//                5 -> 6 -> 4
//            (+) 7 -> 0 -> 8    --> to be printed in reverse as the O/P

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void traverse_list(struct node *head){
    struct node *p = head;
    while(p != NULL){
        printf("%d\n", p->data);
        p = p->next;
    }
}

int len_linked_list(struct node *num){
    struct node *temp = num;
    int count = 0;
    while(temp!=NULL){
        count ++;
        temp = temp->next;
    }
    return count;
}

struct node *create_linked_list(){

    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    struct node *head = create_node(num%10);
    struct node *curr = head;
    num = num/10;  // b/c the initial has already been added to the head

    while(num != 0){
        curr->next = create_node(num%10);
        curr = curr->next;
        num = num/10;
    }
    return head;
}

struct node *add2link_list(struct node *num1, struct node *num2){

    // handle edge case
    if (num1 == NULL) return num2;
    if (num2 == NULL) return num1;

    struct node dummy;
    struct node *temp = &dummy;
    dummy.next = NULL;
    
    int carry = 0;
    while(num1!=NULL || num2!=NULL || carry !=0){
        int val1 = (num1!=NULL) ? num1->data : 0;
        int val2 = (num2!=NULL) ? num2->data : 0;

        int sum = val1 + val2 + carry;
        carry = sum/10;
        temp->next = create_node(sum%10);
        temp = temp->next;

        if (num1 != NULL) num1 = num1->next;
        if (num2 != NULL) num2 = num2->next;
    }
    return dummy.next;
}

int main(){

    struct node *num1 = create_linked_list();
    struct node *num2 = create_linked_list();
    // traverse_list(num1);
    // traverse_list(num2);

    traverse_list(add2link_list(num1, num2));
}