#include "tree.h"

int sumTree(Node *root){

    if(!root){
        return 0;
    }
    int left = sumTree(root->left);
    int right = sumTree(root->right);

    int sumValue = left + right +root->data;
    root->data = left+right;

    return sumValue;

}

int main(){

    Node *root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    sumTree(root);

    inorder(root);

    return 0;
}