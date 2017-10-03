#include "tree.h"

int isTreeHeightBalanced(Node *root, int *height){

    if(!root){
        *height = 0;
        return 1;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    int left = isTreeHeightBalanced(root->left,&leftHeight);

    int right = isTreeHeightBalanced(root->right,&rightHeight);

    *height = std::max(leftHeight,rightHeight) + 1;

    if(((leftHeight - rightHeight ) > 1) || ((rightHeight - leftHeight)) >1){
        return 0;
    }
    else{
        return left&&right;
    }

}

int main(){

    int height = 0;

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(7);

    if(isTreeHeightBalanced(root,&height)){
        printf("Tree is height balanced");
    }
    else{
        printf("Tree is not height balanced");
    }
    return 0;
}