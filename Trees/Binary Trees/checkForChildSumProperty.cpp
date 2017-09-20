#include <iostream>

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int childSumProperty(Node *root){
    if(!root){
        return 1;
    }
    if(!root->left && !root->right){
        return 1;
    }
    int left = 0,right = 0;
    if(root->left){
        left = root->left->data;
    }
    if(root->right){
        right = root->right->data;
    }
    return ((left+right == root->data) && childSumProperty(root->left) && childSumProperty(root->right));
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

    Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    printf("%d",childSumProperty(root));
    return 0;
}