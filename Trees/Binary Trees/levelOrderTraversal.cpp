#include <iostream>
#include <queue>
typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;
int heightOfTree(Node *root){
    if(!root){
        return 0;
    }
    return 1+std::max(heightOfTree(root->left),heightOfTree(root->right));
}
int levelOrderTraversalRecursiveHelper(Node *root, int level){
    if(level == 0){
        printf("%d ",root->data);
        return 0;
    }
    if(root->left){
        levelOrderTraversalRecursiveHelper(root->left,level-1);
    }
    if(root->right){
        levelOrderTraversalRecursiveHelper(root->right,level-1);
    }
}
int levelOrderTraversalRecursive(Node *root){
    int height = heightOfTree(root);
    for(int i = 0 ;i < height;i++){
        levelOrderTraversalRecursiveHelper(root,i);
    }
    return 0;
}
int levelOrderTraversalIterative(Node *root){
    if(!root){
        return 0;
    }
    std::queue<Node *> q;
    q.push(root);
    while(q.size()){
        Node *temp = q.front();
        q.pop();
        printf("%d ",temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return 0;
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


    Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    levelOrderTraversalIterative(root);
    //levelOrderTraversalRecursive(root);
    return 0;
}