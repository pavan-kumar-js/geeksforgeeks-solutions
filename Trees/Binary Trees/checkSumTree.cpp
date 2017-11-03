#include "tree.h"
int sumTreeHelper(Node * root, bool & isSumTree) {
    if (!root) {
        return 0;
    }
    if (!root -> left && !root -> right) {
        return root -> data;
    }
    int left = sumTreeHelper(root -> left, isSumTree);
    int right = sumTreeHelper(root -> right, isSumTree);
    if (left + right == root -> data) {
        return left + right + root -> data;
    } else {
        isSumTree = false;
    }
}

bool checkSumTree(Node * root) {
    bool isSumTree = true;
    sumTreeHelper(root, isSumTree);
    return isSumTree;
}


// Method 2
bool checkSumTreeOrNot(Node * root) {
    if (!root || isLeaf(root)) {
        return true;
    }
    if (checkSumTreeOrNot(root -> left) && checkSumTreeOrNot(root -> right)) {
        int ls = 0;
        int rs = 0;
        if (!root -> left) {
            ls = 0;
        } else if (isLeaf(root -> left)) {
            ls = root -> left -> data;
        } else {
            ls = 2 * (root -> left -> data);
        }
        if (!root -> right) {
            ls = 0;
        } else if (isLeaf(root -> right)) {
            rs = root -> right -> data;
        } else {
            rs = 2 * (root -> right -> data);
        }
        return (ls + rs == root -> data);
    }
    return false;
}



int main() {
    Node * root = newNode(26);
    root -> left = newNode(10);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(6);
    root -> right -> right = newNode(3);
    if (checkSumTreeOrNot(root)) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}