#include <iostream>
#include "linkedlist.h"
using namespace std;

int comparteTwoStrings(Node *string1, Node *string2){

    while(string1 && string2 && string1->data == string2->data){
        string1 = string1->next;
        string2 = string2->next;
    }

    if(string1 && string2){
        return (string1->data > string2->data) ? 1: -1;
        }
    if(string1 && !string2){
        return 1;
    }
    if(!string1 && string2){
        return -1;
    }
    return 0;
}
int main(){
    
    Node *list1 = createNode('g');
    list1->next = createNode('e');
    list1->next->next = createNode('e');
    list1->next->next->next = createNode('k');
    list1->next->next->next->next = createNode('s');
    list1->next->next->next->next->next = createNode('a');

    Node *list2 = createNode('g');
    list2->next = createNode('e');
    list2->next->next = createNode('e');
    list2->next->next->next = createNode('k');
    list2->next->next->next->next = createNode('s');
    list2->next->next->next->next->next = createNode('c');

    cout << comparteTwoStrings(list1, list2);
}