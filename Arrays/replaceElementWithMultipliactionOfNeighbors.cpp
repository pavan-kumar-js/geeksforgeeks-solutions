#include<iostream>

int replaceElementWithMultiplication(int *arr, int n){

    int index = 0;
    int previousValue = arr[0];
    if(n==1){
        return 0;
    }

    for(index;index < n - 1;index++){
        int temp = arr[index];
        arr[index] = previousValue * arr[index + 1];
        previousValue = temp;
    }
    arr[index]*=previousValue;
    return 0;
}

void printArray(int *arr, int n){
    int index = 0;

    for (index=0; index < n; index++){
        printf("%d ",arr[index]);
    }

    printf("\n");
}
int main(){

    int arr[] = {2, 3, 4, 5, 6};
    printArray(arr,5);
    replaceElementWithMultiplication(arr,5);
    printArray(arr,5);
    return 0;
}