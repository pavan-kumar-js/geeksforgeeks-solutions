#include "tree.h"
#include <queue>

using namespace std;

void levelOrderLineByLine(Node *root){

    if(!root){
        return;
    }

    queue<Node *> q1,q2;

    q1.push(root);

    while(true){
        if(q1.empty() && q2.empty()){
            break;
        }
        while(!q1.empty()){
            Node *temp = q1.front();
            q1.pop();
            if(temp->left){
                q2.push(temp->left);
            }
            if(temp->right){
                q2.push(temp->right);
            }
            printf("%d ",temp->data);
        }
        printf("\n");
        while(!q2.empty()){
            Node *temp = q2.front();
            q2.pop();
            if(temp->left){
                q1.push(temp->left);
            }
            if(temp->right){
                q1.push(temp->right);
            }
            printf("%d ",temp->data);
        }
        printf("\n");
    }
}
int main(){

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    levelOrderLineByLine(root);

    return 0;
}