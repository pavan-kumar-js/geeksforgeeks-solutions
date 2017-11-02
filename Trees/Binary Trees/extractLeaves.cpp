


#include "tree.h"


Node* createDLLFromTree(Node *root, Node **head){

    if(!root){
        return nullptr;
    }

    if(!root->left && !root->right){
        if(!(*head)){
            *head = root;
        }
        else {
            (*head)->left = root;
            root->right = (*head);
            *head = root;
        }
        return nullptr;
    }
    root->right = createDLLFromTree(root->right,head);
    root->left = createDLLFromTree(root->left,head);

}
int main(){

    Node *head = nullptr;
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    createDLLFromTree(root,&head);

    return 0;
}