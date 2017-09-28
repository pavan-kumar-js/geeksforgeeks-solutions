#include <iostream>
typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int minimumDepthOfTree(Node *root,int depth){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return depth;
    }
    return std::min(minimumDepthOfTree(root->left,depth+1),minimumDepthOfTree(root->right,depth+1));
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


    Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    int height = minimumDepthOfTree(root,1);
    printf("Minimum depth of the tree is %d",height);
    return 0;
}