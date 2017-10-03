#include "tree.h"



int isTreeFoldable(Node *root1,Node *root2){

    if(!root1 && !root2){
        return 1;
    }
    if(!root1 || !root2){
        return 0;
    }

    return isTreeFoldable(root1->left,root2->right) || isTreeFoldable(root1->right,root2->left);

}

int main(){

    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->right  = newNode(4);
    root->right->left = newNode(5);

    if(isTreeFoldable(root->left,root->right)){
        printf("Tree is foldable");
    }
    else{
        printf("Tree is not foldable");
    }

    return 0;
}