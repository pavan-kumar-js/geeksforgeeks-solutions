#include <cstdio>
#include <malloc.h>
#include "linkedlist.h"
Node *addTwoLinkedLists(Node *a, Node *b, int c){
    if(!a && !b){
        return nullptr;
    }
    if(!a || !b){
        if(!c){
            return !a ? b : a;
        }
        Node *exist = (!a?b:a);
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = 1;
        temp->next= nullptr;
        return addTwoLinkedLists(exist,temp,0);
    }

    int sum = a->data + b->data + c;
    int carry = sum/10;
    sum = sum%10;
    auto *res = (Node *)malloc(sizeof(Node));
    res->data = sum;
    res->next = addTwoLinkedLists(a->next,b->next,carry);

    return res;
}
int main()
{
    Node* res = nullptr;
    Node* first = nullptr;
    Node* second = nullptr;

    // create first list 7->5->9->4->6
    addNodeAtTheEnd(&first, 7);
    addNodeAtTheEnd(&first, 5);
    addNodeAtTheEnd(&first, 9);
    addNodeAtTheEnd(&first, 4);
    addNodeAtTheEnd(&first, 6);
    printf("First List is ");
    printLinkedList(first);

    // create second list 8->4
    addNodeAtTheEnd(&second, 8);
    addNodeAtTheEnd(&second, 4);
    printf("Second List is ");
    printLinkedList(second);

    // Add the two lists and see result
    res = addTwoLinkedLists(first, second, 0);
    printf("Resultant list is ");
    printLinkedList(res);

    return 0;
}