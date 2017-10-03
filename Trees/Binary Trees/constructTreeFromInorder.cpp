#include "tree.h"

int findLargest(int *inorderArray,int start,int end){
    if(start == end){
        return start;
    }
    int maxIndex= start,maxValue = 0;

    for(start;start<end;start++){
        if(inorderArray[start]>maxValue){
            maxIndex = start;
            maxValue = inorderArray[start];
        }
    }

    return maxIndex;
}
Node *createTreeFrominorderArray (int *inorderArray,int start,int end){

    if(start>end){
        return nullptr;
    }

    int largest = findLargest(inorderArray,start,end);
    Node *root = newNode(inorderArray[largest]);

    root->left = createTreeFrominorderArray(inorderArray,start,largest-1);
    root->right = createTreeFrominorderArray(inorderArray,largest+1,end);

    return root;
}
int main(){

    int inorderArray[] = {5, 10, 40, 30, 28};

    Node *root = createTreeFrominorderArray(inorderArray,0,4);

    inorder(root);

    return 0;
}