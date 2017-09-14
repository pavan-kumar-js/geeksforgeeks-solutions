#include<iostream>

int findNumberOccuringOddNumberOfTimes( int *arr, int size){

    int index = 0;
    int numberOnce = 0;
    for(index = 0; index < size; index++){
        numberOnce ^= arr[index];
    }

    return numberOnce;
}

int main(){

    int arr[] = {1, 2, 3, 2, 3, 1, 3};

    int number = findNumberOccuringOddNumberOfTimes(arr,7);

    printf("The number that occurs odd number of times is %d",number);

    return 0;
}

