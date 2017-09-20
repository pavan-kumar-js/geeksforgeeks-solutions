#include <iostream>

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int max(int a, int b, int c){
    if(a>b){
        if(a>c){
            return a;
        }
            return c;
    }
    else{
        if(b>c){
            return b;
        }
        return c;
    }
}
int maxNodeInTree(Node *root){
    if(!root){
        return 0;
    }
    return max(root->data,maxNodeInTree(root->left),maxNodeInTree(root->right));
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

    Node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
    printf("%d",maxNodeInTree(root));
    return 0;
}