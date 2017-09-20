#include <iostream>

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

void printNodesWithoutSiblings(Node *root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        return;
    }
    if(!root->left){
            printf("%d ",root->right->data);
    }
    if(!root->right){
    printf("%d ",root->left->data);
    }
    printNodesWithoutSiblings(root->left);
    printNodesWithoutSiblings(root->right);
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

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);

    printNodesWithoutSiblings(root);

    return 0;
}