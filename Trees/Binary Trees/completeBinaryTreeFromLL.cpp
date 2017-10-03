#include<iostream>
#include <queue>
#include "tree.h"

typedef struct ll{
    int data;
    struct ll *next;
}l;


Node *completeBinaryTreeFromLinkedList(l* ll){

    if(!ll){
        return NULL;
    }

    l *temp = ll;
    Node *root = newNode(temp->data);

    std::queue<Node *> q;
    q.push(root);
    while(temp && q.size()){
        Node *t = q.front();
        q.pop();
        Node *left = nullptr,*right = nullptr;
        if(temp->next){
            temp = temp->next;
            left = newNode(temp->data);
            q.push(left);
        }
        if(temp->next){
            temp = temp->next;
            right = newNode(temp->data);
            q.push(right);
        }
        t->left = left;
        t->right = right;
    }
    return root;
}

void push(l** head_ref, int new_data)
{
     l* new_node = (l *)malloc(sizeof(l));
    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}

int main(){

    l* head = NULL;
    push(&head, 36);
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10);

    Node *root = completeBinaryTreeFromLinkedList(head);

    inorder(root);

    return 0;
}