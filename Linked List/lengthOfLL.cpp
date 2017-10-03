#include <iostream>
#include "linkedlist.h"

int lengthOfLL_Iterative(Node *head){
    if(!head){
        return 0;
    }
    int lengthCounter = 0;

    Node *iterator = head;
    while(iterator){
        lengthCounter++;
        iterator = iterator -> next;
    }
    return lengthCounter;
}


int lengthOfLL_Recursive(Node *head){
    if(!head){
        return 0;
    }
    return 1+lengthOfLL_Recursive(head->next);
}

int main(){

    Node *head = NULL;
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 3);
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 2);
    addNodeAtTheEnd(&head, 1);

    int lengthOfLL = lengthOfLL_Recursive(head);

    //int lengthOfLL = lengthOfLL_Iterative(head);

    printf("Length of the linked list is %d",lengthOfLL);

    return 0;
}