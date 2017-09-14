
#include<iostream>

int findMissingNumber( int *arr, int size){

    int index = 0;
    int xorOnce = 0, xorTwo = 0;
    for(index = 0; index < size; index++){
        xorOnce ^= arr[index];
    }

    for(index = 1; index < size+1; index++){}
    {
        xorTwo ^= index;
    }

    return xorOnce ^ xorTwo;
}

int main(){

    int arr[] = {1, 2, 4, 6, 3, 7, 8};

    int number = findMissingNumber(arr,7);

    printf("The missing number is %d",number);

    return 0;
}

