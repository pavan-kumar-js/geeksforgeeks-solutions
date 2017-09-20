#include <iostream>

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int areIdenticatl(Node *root1, Node *root2){
    if(!root1 && !root2){
        return 1;
    }
    if(!root1 || !root2){
        return 0;
    }
    return ((root1->data == root2->data) && areIdenticatl(root1->left,root2->left) && areIdenticatl(root1->right,root2->right));
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

    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
    root1->right->right->left = newNode(8);

    Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    root2->right->left = newNode(6);
    root2->right->right = newNode(7);
    root2->right->right->left = newNode(8);


    printf("%d",areIdenticatl(root1,root2));
    return 0;
}