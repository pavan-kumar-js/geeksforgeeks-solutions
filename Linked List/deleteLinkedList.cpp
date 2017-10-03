#include <iostream>
#include "linkedlist.h"

void deleteLinkedList_Iterative(Node **head){
    if(!(*head)){
        return;
    }
    Node *iterator;
    while(*head){
        iterator = (*head)->next;
        (*head)->next = nullptr;
        free(head);
        *head = iterator;
    }
}

void deleteLinkedList_Recursive(Node *head){
    if(!head){
        return;
    }
    deleteLinkedList_Recursive(head->next);
    delete head;
}

int main(){

    Node *head = nullptr;
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 4);
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 12);
    addNodeAtTheEnd(&head, 1);

    //deleteLinkedList_Recursive(head);
    deleteLinkedList_Iterative(&head);

    //printLinkedList(head);

    return 0;
}