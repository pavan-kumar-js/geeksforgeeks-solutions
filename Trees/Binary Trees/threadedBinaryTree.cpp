

#include <queue>
#include <malloc.h>
#include <cstdio>
#include <iostream>


using namespace std;
typedef struct node{
    int data;
    struct node *left,*right;
    bool isThreaded;
}Node ;
void inOrderQueue(Node *root, queue<Node *> &q){
    if(!root){
        return;
    }
    if(root->left){
        inOrderQueue(root->left,q);
    }

    q.push(root);

    if(root->right){
        inOrderQueue(root->right,q);
    }

}
Node *newNode(int data){

    auto *temp = (Node *)malloc(sizeof(Node));

    temp->data = data;
    temp->left = temp->right = nullptr;
    temp->isThreaded = false;

    return temp;
}
void createThreadedBinaryTreeHelper(Node *root, queue<Node *> &q){

    if(!root){
        return;
    }

    if(root->left){
        createThreadedBinaryTreeHelper(root->left,q);
    }
    q.pop();
    if(root->right){
        createThreadedBinaryTreeHelper(root->right,q);
    }
    else{
        Node *temp = q.front();
        root->right =temp;
        root->isThreaded = true;
    }
}

Node* createThreadedBinaryTree(Node *root){

    queue<Node *> q;

    inOrderQueue(root,q);

    q.push(nullptr);
    createThreadedBinaryTreeHelper(root,q);


}

Node *leftMost(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Function to do inorder traversal of a threaded
// binary tree
void threaded_inorder(Node *root)
{
    if (!root) return;

    // Find the leftmost node in Binary Tree
    Node *cur = leftMost(root);

    while (cur)
    {
        cout << cur->data << " ";
        if (cur->isThreaded)
            cur = cur->right;

        else // Else go to the leftmost child in right subtree
            cur = leftMost(cur->right);
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

    createThreadedBinaryTree(root);

    threaded_inorder(root);

    return 0;
}