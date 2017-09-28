#include <iostream>
#include <queue>
typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int checkLevelOfAllLeaves(Node *root, int level, int *leafLevel){
    if(!root){
        return 0;
    }
    if(!root->left&&!root->right){
        if(*leafLevel == 0) {
            *leafLevel = level;
        }
        else if(*leafLevel != level && *leafLevel!=-1) {
        *leafLevel = -1;
        }
    }
    checkLevelOfAllLeaves(root->left,level+1,leafLevel);
    checkLevelOfAllLeaves(root->right,level+1,leafLevel);
    return 1;
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


    Node *root = newNode(12);
    root->left = newNode(5);
    root->right = newNode(7);
    root->left->left = newNode(3);
    root->right->right = newNode(1);

    int leafLevel = 0;
    checkLevelOfAllLeaves(root,0,&leafLevel);

    if(leafLevel != -1){
        printf("All leaves are in the same level");
    }
    else{
        printf("All leaves are not in the same level");
    }
    return 0;
}