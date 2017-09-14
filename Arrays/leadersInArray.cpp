#include<iostream>



int printLeaders(int *arr, int size){

    int index = 0;
    int max = INT_MIN;

    //Scan elements from the right
    for(index = size - 1; index >= 0; index--){
        if(arr[index] > max){
            printf("%d ", arr[index]);
            max = arr[index];
        }
    }

    return 0;
}

int main(){

    int arr[] = {16, 17, 4, 3, 5, 2};
    printLeaders(arr,6);
    return 0;
}