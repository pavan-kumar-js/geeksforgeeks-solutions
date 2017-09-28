#include <iostream>
typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int sumOfLeftLeaves(Node *root,int isLeft){
    if(!root){
        return 0;
    }
    int sum = 0;
    if(!root->left && !root->right && isLeft){
        sum = root->data;
    }
    return sum + sumOfLeftLeaves(root->left, 1) + sumOfLeftLeaves(root->right,0);
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


    Node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);

    int sumOfLL = sumOfLeftLeaves(root,0);
    printf("Sum of all left level leaves is %d",sumOfLL);
    return 0;
}