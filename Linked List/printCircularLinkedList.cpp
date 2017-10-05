#include <malloc.h>
#include <stdio.h>
#include "linkedlist.h"

void push(Node **head_ref, int data)
{
    auto *ptr1 = (Node *)malloc(sizeof(Node));
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != nullptr)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}

void printCircularLinkedList(Node *head){
    if(!head){
        return;
    }
    Node *iterator = head;
    do{
        printf("%d ",iterator->data);
        iterator = iterator->next;
    }
    while(iterator!=head);

}


int main(){
    Node *head = nullptr;

    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    //Printing circular linked list
    printCircularLinkedList(head);

    return 0;
}