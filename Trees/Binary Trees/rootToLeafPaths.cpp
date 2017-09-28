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
void printPath(vector<int> vec){
    vector<int>::iterator it;
    for(it = vec.begin(); it!=vec.end();it++){
        cout << *it << " ";
    }
    printf("\n");
}
int printRootToLeaf(Node *root,vector<int> vec){
    if(!root){
        return 0;
    }
    vec.push_back(root->data);
    if(!root->left && !root->right){
        printPath(vec);
    }
    printRootToLeaf(root->left,vec);
    printRootToLeaf(root->right,vec);
    return 0;
}

int main() {


    struct node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);

    std::vector<int> x;
    printRootToLeaf(root,x);
    return 0;
}