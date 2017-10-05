#include <cstdio>
#include "linkedlist.h"

int printMiddleOfList(Node *head){
    if(!head){
        return 0;
    }
    Node *slow = head,*fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast= fast->next->next;
    }
    return slow->data;
}

int main(){

    Node* head = nullptr;
    int i;

    for (i=1; i<6; i++)
    {
        addNodeAtTheEnd(&head, i);
        printLinkedList(head);
        int middle = printMiddleOfList(head);
        printf("Middle of the list is %d\n",middle);
    }
    return 0;
}
