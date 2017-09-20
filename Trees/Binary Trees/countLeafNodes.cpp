#include <iostream>

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int countLeafNodes(Node *root){
    if(!root){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }
    return countLeafNodes(root->left)+countLeafNodes(root->right);
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

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    //root->left->right = newNode(5);
    //root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    printf("%d",countLeafNodes(root));
    return 0;
}