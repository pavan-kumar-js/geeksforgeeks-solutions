
#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

typedef struct LinkedListNode{
    int data;
    struct LinkedListNode *next;
}Node;

Node* createNode(int data);
void printLinkedList(Node *head);
void addNodeAtTheEnd(Node **head, int data);
void deleteLinkedList(Node **head);
void printLinkedListReverse(Node *head);
int sizeOfLinkedList(Node *head);

#endif //LINKEDLIST_LINKEDLIST_H
