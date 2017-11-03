

#include <map>
#include "tree.h"
using namespace std;

void verticalHelper(Node *root,int level,map<int,int> &hash){
    if(!root){
        return;
    }
    int temp = hash[level];
    hash[level] = temp+root->data;

    verticalHelper(root->left,level-1,hash);
    verticalHelper(root->right,level+1,hash);
}

void verticalSum(Node *root){

    map<int,int> hash;
    verticalHelper(root,0,hash);

    map<int,int>::iterator i;
    for(i=hash.begin();i!=hash.end();i++){
        printf("%d ",i->second);
    }
}
int main(){

    Node *root  = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);


    verticalSum(root);


    return 0;
}