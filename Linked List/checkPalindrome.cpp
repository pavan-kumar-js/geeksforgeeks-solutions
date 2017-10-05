#include <malloc.h>
#include <cstdio>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    string data;
    struct node *next;
}node;

node *newNode(const char* data){

    auto *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next= nullptr;

    return temp;
}
bool isPalindrome(string s){
    int i =0;
    int j = s.length();
    j-=1;

    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
bool checkPalindrome(node *head){
    string str = "";

    node *iterator = head;
    while(iterator){
        str.append(iterator->data);
        iterator = iterator->next;
    }
    return isPalindrome(str);
}

int main(){

    node *head = newNode("a");
    head->next = newNode("bc");

    head->next->next = newNode("d");
    head->next->next->next = newNode("dcb");
    head->next->next->next->next = newNode("a");

    if(checkPalindrome(head)){
        printf("Given linked list is a palindrome");
    }
    else{
        printf("Given list is not a palindrome");
    }

    return 0;
}