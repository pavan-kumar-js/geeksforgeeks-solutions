#include <vector>
#include "tree.h"

using namespace std;

void constructInorder(Node *root,vector<int> &nodes){

    if(!root){
        return;
    }

    constructInorder(root->left,nodes);
    nodes.push_back(root->data);
    constructInorder(root->right,nodes);

}
Node* convertTreeToBalancedTreeHelper(int start, int end, vector<int> nodes){
    if(start>end){
        return nullptr;
    }

    int mid = (start+end)/2;
    Node *temp = newNode(nodes[mid]);
    temp->left = convertTreeToBalancedTreeHelper(start,mid-1,nodes);
    temp->right = convertTreeToBalancedTreeHelper(mid+1,end,nodes);
    return temp;

}
Node* convertTreeToBalancedTree(Node *root){
    vector<int> nodes;
    constructInorder(root,nodes);
    int size = nodes.size();
    root = convertTreeToBalancedTreeHelper(0,size-1,nodes);
    return root;
}
int main(){

    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);

    root = convertTreeToBalancedTree(root);

    preorder(root);
    return 0;
}