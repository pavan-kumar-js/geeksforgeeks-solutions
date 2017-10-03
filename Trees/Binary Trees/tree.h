#include<iostream>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* newNode(int data){


    auto *temp = (Node *)malloc(sizeof(Node));

    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;

    return temp;
}
void inorder(Node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


void preorder(Node *root){
    if(!root){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}