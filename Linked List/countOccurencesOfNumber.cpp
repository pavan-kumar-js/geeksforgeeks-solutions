#include <iostream>
#include "linkedlist.h"

int countOccurencesOfNumberInLinkedList(Node *head, int number){

    if(!head){
        return 0;
    }
    Node *iterator = head;
    int count = 0;

    while(iterator){
        if(iterator->data == number){
            count++;
        }
        iterator = iterator -> next;
    }

    return count;
}
int main() {

    Node* head = nullptr;
    addNodeAtTheEnd(&head,1);
    addNodeAtTheEnd(&head,3);
    addNodeAtTheEnd(&head,1);
    addNodeAtTheEnd(&head,2);
    addNodeAtTheEnd(&head,1);

    int count = countOccurencesOfNumberInLinkedList(head,1);

    printf("Number occurred %d times in the list",count);

    return 0;
}