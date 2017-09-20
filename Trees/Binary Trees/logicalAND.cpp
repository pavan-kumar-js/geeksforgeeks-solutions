#include <iostream>

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int logicalAND(Node *root){
    if(!root->left && !root->right){
        return root->data;
    }
    int left = logicalAND(root->left);
    int right = logicalAND(root->right);
    root->data = (left && right);
}

struct node* newNode(int data)
{
    auto *node = (Node *)
            malloc(sizeof(Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return(node);
}

int main() {

    Node *root=newNode(0);
    root->left=newNode(1);
    root->right=newNode(0);
    root->left->left=newNode(0);
    root->left->right=newNode(1);
    root->right->left=newNode(1);
    root->right->right=newNode(1);


    logicalAND(root);
    return 0;
}