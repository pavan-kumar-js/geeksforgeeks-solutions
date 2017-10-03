#include "tree.h"

int deepestLeftLeafNode(Node *root, int isLeft, int level,int *maxLevel, int *deepest){
    if(!root){
        return -1;
    }

    if(!root->left &&!root->right && isLeft){
        if(level > *maxLevel){
            *deepest = root->data;
        }
    }

    deepestLeftLeafNode(root->left,1,level+1,maxLevel,deepest);
    deepestLeftLeafNode(root->right,0,level+1,maxLevel,deepest);

}

int main(){

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

    int deepest = 0,maxLevel = 0;

    deepestLeftLeafNode(root,0,0,&maxLevel,&deepest);

    printf("%d is the deepest left node\n",deepest);

    return 0;
}