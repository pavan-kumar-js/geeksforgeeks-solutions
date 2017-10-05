#include "linkedlist.h"

Node *sortLLOf012(Node *head){

    if(!head || !head->next){
        return head;
    }
    Node *zero_f = nullptr,*zero_last = nullptr;
    Node *one_f = nullptr,*one_last = nullptr;
    Node *two_f = nullptr,*two_last = nullptr;

    Node *iterator = head;
    while(iterator){

        if(iterator->data == 0){
            if(!zero_f){
                zero_f = zero_last = iterator;
            }
            else{
                zero_last -> next= iterator;
                zero_last = zero_last->next;
            }

        }
        else if(iterator->data == 1){
            if(!one_f){
                one_f = one_last = iterator;
            }
            else{
                one_last -> next= iterator;
                one_last = one_last->next;
            }

        }
        else if(iterator->data == 2){
            if(!two_f){
                two_f = two_last = iterator;
            }
            else{
                two_last -> next= iterator;
                two_last = two_last->next;
            }

        }
        iterator = iterator->next;
    }
    zero_last->next =one_f;
    one_last ->next = two_f;
    head = zero_f;
    return head;
}


int main(){

    Node *head = nullptr;

    addNodeAtTheEnd(&head, 0);
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 0);
    addNodeAtTheEnd(&head, 2);
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 2);
    addNodeAtTheEnd(&head, 1);
    addNodeAtTheEnd(&head, 2);

    printLinkedList(head);

    head = sortLLOf012(head);

    printLinkedList(head);

    return 0;
}