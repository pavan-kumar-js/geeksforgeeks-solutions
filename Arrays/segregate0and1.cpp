#include<iostream>

int segregate0sand1s( int *arr, int size){

    int start = 0, end = size-1;
    while(start < end){

        while( !arr[start] && start < end){
            start++;
        }

        while( arr[end] && start < end){
            end--;
        }

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    return 0;
}

void printArray (int *arr, int size){

    int index = 0;

    for( index; index < size; index++){
        printf("%d ",arr[index]);
    }

    printf("\n");
}
int main(){

    int arr[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};

    printArray(arr,10);
    segregate0sand1s(arr,10);
    printArray(arr,10);

    return 0;
}
