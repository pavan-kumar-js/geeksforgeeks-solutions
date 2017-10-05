#include <cstdlib>
#include "linkedlist.h"

void deleteAtPosition(Node **head, int key){

    if(!(*head)){
        return;
    }

    if(key == 0){
        (*head) = (*head)->next;
        return;
    }

    Node *iterator = *head;
    while(--key && iterator->next->next){
        iterator = iterator->next;
    }
    Node *temp = iterator->next;
    iterator->next = temp->next;
    temp->next = nullptr;
    free(temp);
}

int main(){

    Node *head = nullptr;
    addNodeAtTheEnd(&head, 8);
    addNodeAtTheEnd(&head, 2);
    addNodeAtTheEnd(&head, 3);
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 7);

    printLinkedList(head);

    int key = 0;
    deleteAtPosition(&head,key);

    printLinkedList(head);

    return 0;
}