#include <iostream>
#include "linkedlist.h"

Node *rotateLinkedList(Node *head, int k){
    if(k<=0 || !head || !head->next){
        return head;
    }
    int sizeOfList = sizeOfLinkedList(head);
    k = k%sizeOfList ;

    Node *iterator = head;
    while(--k && iterator->next){
        iterator = iterator->next;
    }

    Node *temp = iterator->next;
    iterator->next = nullptr;
    iterator = temp;

    while(iterator->next){
        iterator = iterator->next;
    }
    iterator->next = head;
    return temp;
}

int main(){

    Node *head = nullptr;
    addNodeAtTheEnd(&head,10);
    addNodeAtTheEnd(&head,20);
    addNodeAtTheEnd(&head,30);
    addNodeAtTheEnd(&head,40);
    addNodeAtTheEnd(&head,50);
    addNodeAtTheEnd(&head,60);

    printLinkedList(head);

    head = rotateLinkedList(head,4);

    printLinkedList(head);


    return 0;
}