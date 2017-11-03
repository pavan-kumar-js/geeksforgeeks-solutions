

#include <map>
#include "tree.h"
using namespace std;

void diagonalHelper(Node *root,int level,map<int,int> &hash){
    if(!root){
        return;
    }
    int temp = hash[level];
    hash[level] = temp+root->data;

    diagonalHelper(root->left,level+1,hash);
    diagonalHelper(root->right,level,hash);
}

void diagonalSum(Node *root){

    map<int,int> hash;
    diagonalHelper(root,0,hash);

    map<int,int>::iterator i;
    for(i=hash.begin();i!=hash.end();i++){
        printf("%d ",i->second);
    }
}
int main(){

    Node *root  = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(9);
    root->left->left->right   = newNode(10);
    root->left->right  = newNode(6);
    root->left->right->left  = newNode(11);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(7);


    diagonalSum(root);


    return 0;
}