#include<iostream>

int replaceElementWithGreatestElementOnRightSide( int *arr, int size){

    int index = size - 1;
    int maxOnRight = -1;

    while(index >= 0){
        if(arr[index] > maxOnRight){
            maxOnRight = arr[index];
        }
        arr[index] = maxOnRight;
        index --;
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

    int arr[] = {16, 17, 4, 3, 5, 2};

    printArray(arr,6);
    replaceElementWithGreatestElementOnRightSide(arr,6);
    printArray(arr,6);

    return 0;
}
