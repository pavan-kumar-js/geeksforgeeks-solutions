#include<iostream>
#include "linkedlist.h"

int getNthNode(Node *head, int index){

    if(!head){
        return -1;
    }

    Node *iterator = head;

    while(index-- && iterator){
        iterator = iterator -> next;
    }

    if(iterator){
        return iterator->data;
    }
    return -1;
}

int main(){

    Node *head = NULL;
    addNodeAtTheEnd(&head,1);
    addNodeAtTheEnd(&head,12);
    addNodeAtTheEnd(&head,1);
    addNodeAtTheEnd(&head,4);
    addNodeAtTheEnd(&head,1);

    int index = 3;
    int nthNode = getNthNode(head, index);

    printf("%d Node is %d\n",index,nthNode);

    return 0;
}