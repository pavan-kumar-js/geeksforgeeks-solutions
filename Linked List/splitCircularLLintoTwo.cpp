#include <cstdio>
#include <malloc.h>
#include "linkedlist.h"

void splitList(Node *head, Node **head1,Node **head2){

    Node *iterator = head;
    while(iterator->next!=head){
        iterator = iterator->next;
    }

    Node *slow = head, *fast = head;
    while(fast->next!=head && fast->next->next!=head){
        slow= slow->next;
        fast = fast->next->next;
    }
    *head2 = slow->next;
    slow->next = head;
    *head1 = head;
    iterator->next= *head2;
}

void printList(Node *head)
{
    if(!head){
        return;
    }
    Node *temp = head;
    printf("\n");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
}

void push(Node **head_ref, int data)
{
    Node *ptr1 = (Node *)malloc(sizeof(Node));
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    /* If linked list is not NULL then set the next of
      last node */
    if(*head_ref != NULL)
    {
        while(temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */

    *head_ref = ptr1;
}

int main(){

    Node *head = nullptr;
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    push(&head, 8);
    push(&head, 15);



    printf("Original Circular Linked List");
    printList(head);

    /* Split the list */
    splitList(head, &head1, &head2);

    printf("\nFirst Circular Linked List");
    printList(head1);

    printf("\nSecond Circular Linked List");
    printList(head2);

    return 0;
}