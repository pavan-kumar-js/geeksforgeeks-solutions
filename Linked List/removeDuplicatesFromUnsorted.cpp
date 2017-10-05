#include<iostream>
#include <map>
#include <vector>
#include "linkedlist.h"
#include <algorithm>
using namespace std;

void removeDuplicatesFromUnsortedList(Node *head){

    vector<int> v;
    Node *prev = head,*iterator = head->next;
    v.push_back(head->data);
    while(iterator){
        if(std::find(v.begin(), v.end(), iterator->data) != v.end()){
            prev->next = iterator->next;
            iterator->next = nullptr;
            free(iterator);
            iterator = prev->next;
            continue;
        }
        v.push_back(iterator->data);
        prev = prev->next;
        iterator = iterator ->next ;
    }

}
int main(){

    Node *head = nullptr;

    addNodeAtTheEnd(&head,10);
    addNodeAtTheEnd(&head,12);
    addNodeAtTheEnd(&head,11);
    addNodeAtTheEnd(&head,11);
    addNodeAtTheEnd(&head,12);
    addNodeAtTheEnd(&head,11);
    addNodeAtTheEnd(&head,10);

    printLinkedList(head);

    removeDuplicatesFromUnsortedList(head);

    printLinkedList(head);

    return 0;
}