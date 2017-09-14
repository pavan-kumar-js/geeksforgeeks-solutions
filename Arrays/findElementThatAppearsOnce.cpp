#include<iostream>

int findElementAppearsOnce( int *arr, int size){

    int index = 0;
    int numberOnce = arr[index];
    for(index = 1; index < size; index++){
        numberOnce ^= arr[index];
    }

    return numberOnce;
}

int main(){

    int arr[] = {7, 3, 5, 4, 5, 3, 4};

    int number = findElementAppearsOnce(arr,7);

    printf("The number that appears once is %d",number);

    return 0;
}
