#include "tree.h"

void maxRootHelper(Node *root,int &max,int sum){

    if(!root){
        return ;
    }
    if(!root->left && !root->right){
        sum+=root->data;

        if(sum > max) {
            max = sum;
        }
        return;
    }
    sum+=root->data;
    maxRootHelper(root->left,max,sum);
    maxRootHelper(root->right,max,sum);

}

int maxRootToLeafPathSum(Node *root){
    int max = 0;
    int sum = 0;
    maxRootHelper(root,max,sum);
    return max;
}
int main(){

    Node *root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    int maxSumPath = maxRootToLeafPathSum(root);

    printf("Maximum sum from root to leaf is %d\n",maxSumPath);
    return 0;
}