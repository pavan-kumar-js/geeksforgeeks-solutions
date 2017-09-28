#include <iostream>
typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int diffOddAndEven(Node *root,int level){
    if(!root){
        return 0;
    }
    level*=-1;
    return (root->data * level) + diffOddAndEven(root->left, level) + diffOddAndEven(root->right,level);
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


    Node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);

    int sumDiff = diffOddAndEven(root,-1);
    printf("Difference between sum of odd and even level nodesis %d",sumDiff);
    return 0;
}