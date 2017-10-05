#include<iostream>
#include "linkedlist.h"


Node* reverseLinkedList(Node *head){

    if(!head || !head->next){
        return head;
    }
    Node *temp = head->next;
    head->next = nullptr;
    Node* newHead = reverseLinkedList(temp);
    temp->next = head;

    return newHead;
}

int main(){

    Node *head = nullptr;

    addNodeAtTheEnd(&head,1);
    addNodeAtTheEnd(&head,2);
    addNodeAtTheEnd(&head,3);
    addNodeAtTheEnd(&head,4);
    addNodeAtTheEnd(&head,5);

    printLinkedList(head);

    head = reverseLinkedList(head);

    printLinkedList(head);

    return 0;
}