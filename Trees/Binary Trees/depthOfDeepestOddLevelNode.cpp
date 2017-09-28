#include <iostream>

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int maximum(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}
int depthOfDeepestOddLevelNode(Node *root, int level){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right && level&1){
        return level;
    }
    return maximum(depthOfDeepestOddLevelNode(root->left,1+level),depthOfDeepestOddLevelNode(root->right,1+level));
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


    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    root->right->right->right->right->left = newNode(11);

    int depth = depthOfDeepestOddLevelNode(root,1);
    printf("depth of deepest odd level node is %d",depth);
    return 0;
}