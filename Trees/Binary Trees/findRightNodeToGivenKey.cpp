#include <iostream>
#include <queue>
typedef struct node{
    int data;
    struct node *left ;
    struct node *right;
}Node ;

int findRightNode(Node *root, int key){
    if(!root){
        return 0;
    }
    int level = 0;
    std::queue<Node *> q;
    std::queue<int> ql;
    q.push(root);
    ql.push(level);
    while(q.size()){
        Node *temp = q.front();
        int level = ql.front();
        ql.pop();
        q.pop();
        if(key == temp->data){
            if(q.size() && ql.front()==level){
                printf("%d is to the right of %d\n",q.front()->data,key);
            }
            else{
                printf("There is no right node to %d\n",key);
            }
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


    Node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);

    findRightNode(root, 10);
    findRightNode(root, 2);
    findRightNode(root, 6);
    findRightNode(root, 5);
    findRightNode(root, 8);
    findRightNode(root, 4);
    return 0;
}