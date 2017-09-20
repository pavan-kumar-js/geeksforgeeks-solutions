#include <iostream>
#include<stack>

using namespace std;

typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int searchForKey(Node *root, int key){

    if(!root){
        return -1;
    }
    int keyFound = -1;
    stack<Node *> s;
    s.push(root);
    while(!s.empty()){
        Node *temp = s.top();
        s.pop();
        if(temp->data == key)
        {
            keyFound = 1;
        }
        if(temp->left){
            s.push(temp->left);
        }
        if(temp->right){
            s.push(temp->right);
        }
    }
    return keyFound;
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

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    printf("%d",searchForKey(root,10));
    return 0;
}