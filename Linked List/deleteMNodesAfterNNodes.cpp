#include <cstdlib>
#include "linkedlist.h"

void deleteMNodesAfterN(Node *head, int m, int n){

    if(!head){
        return;
    }

    Node *iterator = head;

    while(iterator){
        int outer = m, del = n;
        while(--outer){
            iterator = iterator -> next;
        }
        Node *temp = iterator->next;
        while(del-- && temp){
            temp = temp->next;
        }
        free(iterator->next);
        iterator->next = temp;
        iterator = temp;
    }
}

int main(){


    Node *head = nullptr;
    int m=2, n=3;
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 2);
    addNodeAtTheEnd(&head, 3);
    addNodeAtTheEnd(&head, 4);
    addNodeAtTheEnd(&head, 5);
    addNodeAtTheEnd(&head, 6);
    addNodeAtTheEnd(&head, 7);
    addNodeAtTheEnd(&head, 8);
    addNodeAtTheEnd(&head, 9);
    addNodeAtTheEnd(&head, 10);

    printLinkedList(head);

    deleteMNodesAfterN(head,m,n);

    printLinkedList(head);

    return 0;
}