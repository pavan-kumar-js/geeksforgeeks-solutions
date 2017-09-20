#include <iostream>

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int checkLevelOfNode(Node *root, int data, int level){
    if(!root){
        return 0;
    }
    if(root->data == data){
        return level;
    }
    int left = checkLevelOfNode(root->left, data, level+1);
    if(left)
    {
        return left;
    }
    return checkLevelOfNode(root->right, data, level+1);
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
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);

    int data = 8;

    printf("%d",checkLevelOfNode(root, data, 0));
    return 0;
}