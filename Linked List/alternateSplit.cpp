#include <cstdio>
#include "linkedlist.h"

void alternateSplit(Node *head, Node **a, Node **b){
    if(!head){
        return;
    }
    int count = 0;
    Node *iterator = head,*temp_a = nullptr,*temp_b = nullptr;
    while(iterator){
        if(!temp_a){
            temp_a  = iterator;
            *a = temp_a;
        }
        else if(!temp_b){
            temp_b  = iterator;
            *b = temp_b;
        }
        else{
            if(!count){
                temp_a ->next = iterator;
                temp_a = iterator;
            }
            else{
                temp_b ->next = iterator;
                temp_b = iterator;
            }
            iterator= iterator->next;
            temp_a->next = nullptr;
            temp_b->next = nullptr;
            count = !count;
            continue;
        }
        iterator= iterator->next;
    }
}

int main(){

    Node* head = nullptr;
    Node* a = nullptr;
    Node* b = nullptr;

    addNodeAtTheEnd(&head, 0);
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 2);
    addNodeAtTheEnd(&head, 3);
    addNodeAtTheEnd(&head, 4);
    addNodeAtTheEnd(&head, 5);


    printf("\n Original linked List:  ");
    printLinkedList(head);

    /* Remove duplicates from linked list */
    alternateSplit(head, &a, &b);

    printf("\n Resultant Linked List 'a' ");
    printLinkedList(a);

    printf("\n Resultant Linked List 'b' ");
    printLinkedList(b);
}