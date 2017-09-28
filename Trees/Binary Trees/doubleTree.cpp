
#include <iostream>

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

void doubleTree(Node *root){
    if(!root){
        return;
    }
    Node *temp = newNode(root->data);
    temp->left = root->left;
    root->left = temp;
    doubleTree(root->left->left);
    doubleTree(root->right);
}

void printTree(Node *root){
    if(!root){
        return;
    }
    printTree(root->left);

    printf("%d ",root->data);

    printTree(root->right);
}
int main() {


    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printTree(root);

    doubleTree(root);
    printf("\n");
    printTree(root);
    return 0;
}