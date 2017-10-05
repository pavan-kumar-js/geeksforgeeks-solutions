
#include <cstdio>
#include "linkedlist.h"

bool loopExists(Node *head){
    if(!head || !head->next){
        return false;
    }
    Node *slow = head,*fast = head;
    while(fast->next && fast->next->next){

        slow = slow->next;
        fast = fast->next->next;

        if(slow->next == fast->next){
            return true;
        }


    }
    return false;
}
int main(){

    Node* head = nullptr;

    addNodeAtTheEnd(&head, 10);
    addNodeAtTheEnd(&head, 15);
    addNodeAtTheEnd(&head, 4);
    addNodeAtTheEnd(&head, 20);

    /* Create a loop for testing */
    head->next->next->next->next = head->next;

    if(loopExists((head))){
        printf("Loop exists");
    }
    else{
        printf("There is no loop");
    }

    return 0;
}