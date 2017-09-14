#include <iostream>

void reverseArray(int n, int arr[n]){

    int i = 0;
    while( i < (n - i -1)){
        int temp = arr[i];
        arr[i] = arr[ n - i - 1];
        arr[ n - i - 1] = temp;
        i++;
    }
}

void reverseString(char *str){
    int i=0;
    int j = strlen(str) -1;
    while(i < j){
        char x = str[i];
        str[i] = str[j];
        str[j] = x;
        i++;
        j--;
    }
}
void printString(char *str){
    printf("%s\n",str);
}

void printArr(int n,int arr[n]){

    int i;

    for( i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {1,2,3,4,5};
    char str[] = "pavan";
    printArr(5,arr);
    printString(str);
    reverseString(str);
    printString(str);
    reverseArray(5,arr);
    printArr(5,arr);
    return 0;
}