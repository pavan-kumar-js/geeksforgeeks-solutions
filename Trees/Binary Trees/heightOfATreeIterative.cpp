#include <iostream>
#include <queue>

using namespace std;
typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int heightOfTree(Node *root){
    if(!root){
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    int height = 0;
    while(1){
        int nodeCount = q.size();
        if(!nodeCount){
            return height;
        }
        while(nodeCount){
            Node *temp = q.front();
            q.pop();
            nodeCount --;
            if(!nodeCount){
                height++;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
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


    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    root->right->right->right->right->left = newNode(11);

    int height = heightOfTree(root);
    printf("Height of the tree is %d",height);
    return 0;
}