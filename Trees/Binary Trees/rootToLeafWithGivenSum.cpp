#include <iostream>
#include <queue>
#include <stack>

using namespace std;
typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

struct node* newNode(int data)
{
    auto *node = (Node *)
            malloc(sizeof(Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return(node);
}
int rootToLeafWithGivenSum(Node *root, int sum){
    if(!root){
        return 0;
    }
    sum-=root->data;
    if(!root->left && !root->right){
        if(sum){
            return 0;
        }
        return 1;
    }
    return rootToLeafWithGivenSum(root->left,sum) || rootToLeafWithGivenSum(root->right,sum);
}
int main() {


    Node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);

    int sum = 21;

    int pathExists = rootToLeafWithGivenSum(root, sum);
    if(pathExists){
        printf("Path exists with given sum");
    }
    else{
        printf("There is no path with given sum");
    }
    return 0;
}