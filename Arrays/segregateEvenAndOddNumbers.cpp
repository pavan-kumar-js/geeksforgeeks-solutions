#include<iostream>

int segregateEvenAndOdd(int *arr, int n){

    int index = 0,end = n-1;
    while( index < end){
        while ( !(arr[index]%2) && index < end){
            index++;
        }
        while ( (arr[end]%2) && index < end){
            end--;
        }
        int temp = arr[index];
        arr[index] = arr[end];
        arr[end] = temp;
    }
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

    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    printArray(arr,7);
    segregateEvenAndOdd(arr,7);
    printArray(arr,7);
    return 0;
}

