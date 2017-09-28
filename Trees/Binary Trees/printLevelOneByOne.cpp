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

int printLevelOneByOne(Node *root){
    if(!root){
        return 0;
    }
    int level = 0;
    queue<Node *> q;
    queue<int> ql;
    q.push(root);
    ql.push(0);
    while(q.size()){
        Node *temp = q.front();
        level = ql.front();
        q.pop();
        ql.pop();
        printf("%d ",temp->data);
        if(level!=ql.front()){
            printf("\n");
        }
        if(temp->left){
            q.push(temp->left);
            ql.push(level+1);
        }
        if(temp->right){
            q.push(temp->right);
            ql.push(level+1);
        }

    }

    return 0;
}

int main() {


    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printLevelOneByOne(root);

    return 0;
}