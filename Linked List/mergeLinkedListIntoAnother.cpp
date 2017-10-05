#include <cstdio>
#include "linkedlist.h"

void mergeList(Node *root1, Node **root2){
    if(!root1){
        return;
    }
    Node *iterator = root1;

    while(iterator){
        Node *temp = *root2;
        *root2 = (*root2) ->next;
        temp->next= iterator->next;
        iterator->next = temp;
        iterator = iterator->next->next;
    }
}

int main(){


    Node *p = nullptr, *q = nullptr;
    addNodeAtTheEnd(&p, 1);
    addNodeAtTheEnd(&p, 2);
    addNodeAtTheEnd(&p, 3);
    printf("First Linked List:\n");
    printLinkedList(p);

    addNodeAtTheEnd(&q, 4);
    addNodeAtTheEnd(&q, 5);
    addNodeAtTheEnd(&q, 6);
    addNodeAtTheEnd(&q, 7);
    addNodeAtTheEnd(&q, 8);
    printf("Second Linked List:\n");
    printLinkedList(q);

    mergeList(p, &q);

    printf("Modified First Linked List:\n");
    printLinkedList(p);

    printf("Modified Second Linked List:\n");
    printLinkedList(q);

    return 0;

}