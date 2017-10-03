#include<iostream>
#include "linkedlist.h"

void printLLReverseRecursive(Node *head){

    if(!head){
        return;
    }
    printLLReverseRecursive(head->next);
    printf("%d ",head->data);
}

int main(){

    Node *head = nullptr;

    addNodeAtTheEnd(&head, 4);
    addNodeAtTheEnd(&head, 3);
    addNodeAtTheEnd(&head, 2);
    addNodeAtTheEnd(&head, 1);

    printLinkedList(head);

    printLLReverseRecursive(head);

    return 0;
}

