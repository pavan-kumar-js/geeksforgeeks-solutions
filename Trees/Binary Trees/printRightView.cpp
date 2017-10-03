#include "tree.h"

void printRightView(Node *root,int level, int *maxLevel){

    if(!root){
        return;
    }
    if(level > *maxLevel){
        printf("%d ",root->data);
        *maxLevel = level;
    }

    printRightView(root->right,level+1,maxLevel);
    printRightView(root->left,level+1,maxLevel);

}

void printRightHelper(Node *root){

    if(!root){
        return;
    }

    int max = 0;

    printRightView(root,1,&max);
}

int main(){

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    printRightHelper(root);

    return 0;
}