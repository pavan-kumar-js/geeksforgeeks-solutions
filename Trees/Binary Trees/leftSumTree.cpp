

#include "tree.h"


int createLeftSumTree(Node *root){


    if(!root){
        return 0;
    }

    if(!root->left && !root->right){
        return root->data;
    }

    int l = createLeftSumTree(root->left);
    int r = createLeftSumTree(root->right);

    root->data += l;

    return r+root->data;

}

int main(){

    Node *root  = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->right = newNode(6);

    inorder(root);
    printf("\n");
    createLeftSumTree(root);

    inorder(root);

    return 0;
}