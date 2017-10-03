#include "tree.h"

void printNodesHelper(Node* root, int level)
{
    if (level == 1) {
        printf("%d ", root->data);
        return;
    }
    if (root->left) {
        printNodesHelper(root->left, level - 1);
    }
    if (root->right) {
        printNodesHelper(root->right, level - 1);
    }
}
void printNodesBetweenGivenLevel(Node* root, int x, int y)
{
    if (!root) {
        return;
    }

    for (x; x <= y; x++) {
        printNodesHelper(root, x);
        printf("\n");
    }
}
int main()
{
    Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    printNodesBetweenGivenLevel(root, 2, 3);

    return 0;
}