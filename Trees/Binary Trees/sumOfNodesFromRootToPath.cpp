#include<iostream>
#include "tree.h"


int sumOfNodesFromRootToLeaves(Node *root,int value){
    if(!root){
        return 0;
    }

    value = value*10 + root->data;

    if(!root->left && !root->right){
        return value;
    }

    return sumOfNodesFromRootToLeaves(root->left,value) + sumOfNodesFromRootToLeaves(root->right,value);
}

int main(){

    struct node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    int sum = sumOfNodesFromRootToLeaves(root,0);

    printf("Sum of all the numbers that are formed from root to leaf paths is %d\n",sum);

    return 0;
}