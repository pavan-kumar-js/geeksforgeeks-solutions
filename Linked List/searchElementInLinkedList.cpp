#include <cstdio>
#include"linkedlist.h"

bool searchElement_iterative(Node *head, int element){

    if(!head){
        return false;
    }

    Node *iterator = head;
    while(iterator){
        if(iterator->data == element){
            return true;
        }
        iterator = iterator -> next;
    }
    return false;
}

bool searchElement_recursive(Node *head, int element) {

    if(!head){
        return false;
    }
    return head->data == element || searchElement_recursive(head->next,element);
}

int main(){

    Node *head = nullptr;

    addNodeAtTheEnd(&head, 10);
    addNodeAtTheEnd(&head, 30);
    addNodeAtTheEnd(&head, 11);
    addNodeAtTheEnd(&head, 21);
    addNodeAtTheEnd(&head, 14);

    bool elementFound = searchElement_recursive(head, 21);

    if(elementFound) {
        printf("Element is present in the list\n");
    }
    else{
        printf("Element is not present in the list\n");
    }

    return 0;
}