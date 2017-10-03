#include <iostream>
#include "linkedlist.h"


void moveLastElementToFirst(Node **head){

    if(!head){
        return;
    }

    Node *iterator = *head;

    while(iterator->next->next){
        iterator = iterator->next;
    }

    iterator->next->next = *head;
    *head = iterator->next;
    iterator->next = nullptr;

}

int main() {
    Node* head = nullptr;

    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 2);
    addNodeAtTheEnd(&head, 3);
    addNodeAtTheEnd(&head, 4);
    addNodeAtTheEnd(&head, 5);

    printLinkedList(head);

    moveLastElementToFirst(&head);

    printLinkedList(head);

    return 0;
}