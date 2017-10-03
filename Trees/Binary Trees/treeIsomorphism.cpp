#include <iostream>
#include "tree.h"


int isTreeIsomorphic(Node *root1, Node *root2){
    if(!root1 && !root2){
        return 1;
    }
    if(!root1 || !root2){
        return 0;
    }

    return (root1->data == root2->data) && ((isTreeIsomorphic(root1->left,root2->right) && isTreeIsomorphic(root1->right,root2->left))||
            (isTreeIsomorphic(root1->left,root2->left) && isTreeIsomorphic(root1->right,root2->right)));
}

int main(){

    struct node *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);

    struct node *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    n2->right->left   = newNode(4);
    n2->right->right   = newNode(5);
    n2->left->right   = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);

    if(isTreeIsomorphic(n1,n2)){
        printf("Trees are isomorphic");
    }
    else{
        printf("Trees are not isomorphic");
    }

    return 0;
}