#include<iostream>

int findFixedPoint(int *array,int low,int high){

    if(low>high)
    {
        return -1;
    }

    int mid = (low + (high-low)/2);
    if(mid == array[mid]){
        return mid;
    }
    else if(mid > array[mid]){
        return findFixedPoint( array, mid+1, high);
    }
    else {
        return findFixedPoint( array, low, mid - 1);
    }
}

int main(){

    int arr[] = {-10,-5,0,3,10};

    int fixedPoint = findFixedPoint(arr,0,7);

    printf("%d the fixed point",fixedPoint);

    return 0;
}