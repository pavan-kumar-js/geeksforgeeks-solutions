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

int reverseLevelOrder(Node *root){
    if(!root){
        return 0;
    }
    stack<int> s;
    queue<Node *> q;
    q.push(root);
    while(q.size()){
        Node *temp = q.front();
        q.pop();
        s.push(temp->data);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    while(s.size()){
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}

int main() {


    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    reverseLevelOrder(root);

    return 0;
}