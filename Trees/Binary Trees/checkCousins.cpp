#include "tree.h"
int areSiblings(Node *root,Node *a,Node *b){
    if(!root){
        return 0;
    }
    if((root->left == a && root->right == b) || (root->left == b && root->right == a)){
        return 1;
    }
    return (areSiblings(root->left,a,b) || areSiblings(root->right,a,b));
}
int levelOfNode(Node *root, Node *node, int level){
    if(!root){
        return 0;
    }
    if(root == node){
        return level;
    }

    return std::max(levelOfNode(root->left,node,level+1),levelOfNode(root->right,node,level+1));

}
int checkCousins(Node *root, Node* a, Node *b){
    int level1 = levelOfNode(root,a,0);
    int level2 = levelOfNode(root,b,0);

    if(!areSiblings(root,a,b) && level1 == level2){
        return 1;
    }
    return 0;
}

int main(){

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    if(checkCousins(root, root->left->left,root->right->left)){
        printf("Nodes are cousins");
    }
    else{
        printf("Nodes are not cousins");
    }

    return 0;
}