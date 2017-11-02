


#include "tree.h"



void convertLeftRightToBottomRight(Node *root){

    if(!root){
        return;
    }
    if(!root->left &&!root->right){
        return;
    }
    convertLeftRightToBottomRight(root->left);
    convertLeftRightToBottomRight(root->right);

    root->left->right = root->right;
    root->right = nullptr;

}

void downRightTraversal(node *root)
{
    if (root != NULL)
    {
        std::cout << root->data << " ";
        downRightTraversal(root->right);
        downRightTraversal(root->left);
    }
}
int main(){

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);

    convertLeftRightToBottomRight(root);
    downRightTraversal(root);
    return 0;
}