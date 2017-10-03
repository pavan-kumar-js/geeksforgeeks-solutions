#include <cstring>
#include <stack>
#include <cstdio>
#include <malloc.h>

using namespace std;

struct et
{
    char value;
    et* left, *right;
};

typedef char* string;

et* newEt(char val){

    et* temp = (et *)malloc(sizeof(et));
    temp->value = val;

    temp->left = nullptr;
    temp->right = nullptr;

    return temp;
}

et *constructExpressionTree(string postfix){

    if(!strlen(postfix)){
        return NULL;
    }

    stack<et *> s;

    int i;

    for(i=0; postfix[i]!='\0';i++){

        if(postfix[i] >= 'a' && postfix[i] <= 'z'){
            s.push(newEt(postfix[i]));
        }
        else{
            et *right = s.top();
            s.pop();
            et *left = s.top();
            s.pop();
            et *root = newEt(postfix[i]);
            root->left = left;
            root->right = right;
            s.push(root);
        }
    }
    return s.top();
}

void etInorder(et *t)
{
    if(t)
    {
        etInorder(t->left);
        printf("%c ", t->value);
        etInorder(t->right);
    }
}

int main(){


    string postfix = "ab+ef*g*-";

    et *root = constructExpressionTree(postfix);

    etInorder(root);

    return 0;
}