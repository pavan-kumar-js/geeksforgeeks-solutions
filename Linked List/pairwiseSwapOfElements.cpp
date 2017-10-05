#include "linkedlist.h"

Node *pairwiseSwap_recursive(Node *head){

    if(!head || !head->next){
        return head;
    }

    Node *rest = head->next->next;

    Node *newHead = head->next;

    head->next->next = head;

    head->next = pairwiseSwap_recursive(rest);

    return newHead;
}
void pairwiseSwap(Node **head){
    if(!(*head) && !(*head)->next){
        return;
    }

    Node *temp = *head;
    Node *temp2 = (*head)->next;
    *head = temp;
    if((*head)->next){
        temp = (*head)->next;
        temp2 = temp->next;
    }

    while(temp->next && temp2->next){
        temp->next = temp2->next;
        temp2->next = temp2->next->next;
        temp = temp->next;
        temp->next = temp2;
        temp = temp2;
        temp2 = temp->next;
    }
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

    head = pairwiseSwap_recursive(head);
    // pairwiseSwap(&head)

    printLinkedList(head);

    return 0;
}