#include <iostream>

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}
int maxDepth(Node *root){
    if(!root){
        return 0;
    }
    return 1+max(maxDepth(root->left),maxDepth(root->right));
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
    printf("%d",maxDepth(root));
    return 0;
}