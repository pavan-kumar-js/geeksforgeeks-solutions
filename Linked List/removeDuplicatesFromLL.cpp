#include <cstdlib>
#include "linkedlist.h"

void removeDuplicates(Node *head){
    if(!head){
        return;
    }

    Node *iterator = head;
    while(iterator && iterator->next){
        if(iterator->data == iterator->next->data){
            Node *temp = iterator->next;
            iterator->next = iterator->next->next;
            free(temp);
        }
        else{
            iterator = iterator->next;
        }
    }
}
int main(){

    Node* head = nullptr;

    addNodeAtTheEnd(&head, 20);
    addNodeAtTheEnd(&head, 13);
    addNodeAtTheEnd(&head, 13);
    addNodeAtTheEnd(&head, 11);
    addNodeAtTheEnd(&head, 11);
    addNodeAtTheEnd(&head, 11);

    printLinkedList(head);

    removeDuplicates(head);

    printLinkedList(head);

    return 0;
}