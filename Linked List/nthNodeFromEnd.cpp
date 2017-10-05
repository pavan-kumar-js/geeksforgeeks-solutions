#include <cstdio>
#include "linkedlist.h"

int getNthNodeFromEnd(Node *head, int n){
    if(!head || (n <= 0)){
        return -1;
    }

    Node *iterator = head;

    while(n-- && iterator){
        iterator = iterator->next;
    }

    while(iterator){
        head = head->next;
        iterator = iterator->next;
    }
    return head->data;
}

int main(){


    Node *head = nullptr;

    addNodeAtTheEnd(&head, 35);
    addNodeAtTheEnd(&head, 15);
    addNodeAtTheEnd(&head, 4);
    addNodeAtTheEnd(&head, 20);

    int key = 3;
    int nEnd = getNthNodeFromEnd(head, key);

    printf("%d'th node from the end is %d\n",key,nEnd);

    return 0;
}