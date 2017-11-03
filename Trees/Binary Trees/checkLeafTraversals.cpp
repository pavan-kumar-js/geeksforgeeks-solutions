

#include "tree.h"
#include <stack>
using namespace std;

bool areLeavesSame(Node *root1, Node *root2) {

    stack<Node *> s1,s2;
    if(!root1 || !root2) {
        return false;
    }

    s1.push(root1);
    s2.push(root2);

    while(!s1.empty() && !s2.empty()) {
        if(s1.empty()||s2.empty()) {
            return false;
        }
        Node *leaf1, *leaf2;
        while(true) {
            leaf1 = s1.top();
            s1.pop();
            if(!leaf1->left && !leaf1->right) {
                break;
            }
            else {
                if(leaf1->right) {
                    s1.push(leaf1->right);
                }
                if(leaf1->left) {
                    s1.push(leaf1->left);
                }
            }
        }


        while(true) {
            leaf2 = s2.top();
            s2.pop();
            if(!leaf2->left && !leaf2->right) {
                break;
            }
            else {
                if(leaf2->right) {
                    s2.push(leaf2->right);
                }
                if(leaf2->left) {
                    s2.push(leaf2->left);
                }
            }
        }
        if(leaf1->data!=leaf2->data) {
            return false;
        }
    }

    return true;
}

int main(){


    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);

    Node *root2 = newNode(0);
    root2->left = newNode(1);
    root2->right = newNode(5);
    root2->left->right = newNode(4);
    root2->right->left = newNode(6);
    root2->right->right = newNode(7);

    if (areLeavesSame(root1, root2))
        printf("Same");
    else
        printf("Not Same");
    return 0;
}