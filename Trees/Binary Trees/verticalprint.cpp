

#include "tree.h"
#include<vector>
#include<map>
using namespace std;
void printVerticalHelper(Node *root,int vLevel, map<int,vector<int>> &h){
    if(!root){
        return;
    }
    h[vLevel].push_back(root->data);
    printVerticalHelper(root->left,vLevel-1,h);
    printVerticalHelper(root->right,vLevel+1,h);
}

void printVertically(Node *root){

    map<int,vector<int>> h;
    printVerticalHelper(root,0,h);

    map<int,vector<int>>::iterator it;

    for(it=h.begin();it!=h.end();it++){

        for(int index = 0;index <it->second.size();index++){
            printf("%d ",it->second[index]);
        }
        printf("\n");
    }

}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    printVertically(root);


    return 0;
}