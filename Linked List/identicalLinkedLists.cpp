#include <printf.h>®
#include "linkedlist.h"

bool listsIdentical(Node *list1, Node *list2){
    if(!list1 && !list2){
        return true;
    }
    if(!list1 || !list2){
        return false;
    }
    while(list1 && list2){

        if(list1->data == list2->data){
            list1 = list1->next;
            list2 = list2->next;
        }
        else{
            return false;
        }
    }
    if(!list1 && !list2){
        return true;
    }
    return false;
}

bool listsIdentical_recursive(Node *list1, Node *list2){
    if(!list1 && !list2){
        return true;
    }
    if(!list1 || !list2){
        return false;
    }
    return list1->data == list2->data && listsIdentical_recursive(list1->next,list2->next);
}

int main(){

    Node *a = nullptr;
    Node *b = nullptr;

    addNodeAtTheEnd(&a, 1);
    addNodeAtTheEnd(&a, 2);
    addNodeAtTheEnd(&a, 3);
    addNodeAtTheEnd(&b, 1);
    addNodeAtTheEnd(&b, 2);
    addNodeAtTheEnd(&b, 3);

    if(listsIdentical(a,b)){
        printf("Lists are identical");
    }
    else{
        printf("Lists are not identical");
    }
    return 0;
}