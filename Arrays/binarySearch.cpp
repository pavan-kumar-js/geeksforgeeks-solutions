#include<iostream>

int binarySearch(int *array,int low,int high,int key){

    if(low>high)
    {
        return -1;
    }

    int mid = (low + (high-low)/2);
    if(key == array[mid]){
        return mid;
    }
    else if(key > array[mid]){
        return binarySearch( array, mid+1, high, key);
    }
    else {
        return binarySearch( array, low, mid - 1, key);
    }
}

int main(){

    int arr[] = {1,3,5,7,9,11,15,17};
    int keyToBeSearched = 16;

    int index = binarySearch(arr,0,7,keyToBeSearched);

    printf("%d is at index %d",keyToBeSearched,index);

    return 0;
}