
#include <iostream>

using namespace std;
typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

Node* lca(Node *root, int a, int b){
    if(!root){
        return 0;
    }
    if(root->data < a && root->data <b){
        return lca(root->right,a,b);
    }
    if(root->data > a && root->data >b){
        return lca(root->left,a,b);
    }
    return root;
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


    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    return 0;
}
