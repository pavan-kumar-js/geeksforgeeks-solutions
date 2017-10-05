
#include <cstdlib>
#include "linkedlist.h"

Node *deleteAlternateNode(Node *head){

    if(!head || !head->next){
        return head;
    }

//    Node *temp = head->next;
//    head->next= head->next->next;
//    temp->next= nullptr;
//    free(temp);                                   // uncomment and replace head->next->next below to head->next

    head->next = deleteAlternateNode(head->next->next);
    return head;
}

int main(){

    Node *head = nullptr;
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 2);
    addNodeAtTheEnd(&head, 3);
    addNodeAtTheEnd(&head, 4);
    addNodeAtTheEnd(&head, 5);
    addNodeAtTheEnd(&head, 6);

    printLinkedList(head);

    head = deleteAlternateNode(head);

    printLinkedList(head);

    return 0;
}
