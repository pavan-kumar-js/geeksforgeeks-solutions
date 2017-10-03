#include<iostream>
#include "tree.h"

int checkSameTrees(Node *t, Node *s){
    if(!s && !t){
        return 1;
    }
    if(!s || !t){
        return 0;
    }
    return (t->data == s->data) && checkSameTrees(t->left,s->left) && checkSameTrees(t->right,s->right);
}
int checkTreeSubTree(Node *t, Node *s){
    if(!s && !t){
        return 1;
    }
    if(!s || !t){
        return 0;
    }
    return checkSameTrees(t,s) || checkTreeSubTree(t->left,s) || checkTreeSubTree(t->right,s);
}

int main(){

    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);

    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);

    if(checkTreeSubTree(T,S)){
        printf("Tree is a sub tree");
    }
    else{
        printf("Tree is not a subtree");
    }

    return 0;
}