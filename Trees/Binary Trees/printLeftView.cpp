#include "tree.h"

void printLeftView(Node *root,int level, int *maxLevel){

    if(!root){
        return;
    }
    if(level > *maxLevel){
        printf("%d ",root->data);
        *maxLevel = level;
    }

    printLeftView(root->left,level+1,maxLevel);
    printLeftView(root->right,level+1,maxLevel);

}

void printLeftHelper(Node *root){

    if(!root){
        return;
    }

    int max = 0;

    printLeftView(root,1,&max);
}

int main(){

    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    printLeftHelper(root);

    return 0;
}