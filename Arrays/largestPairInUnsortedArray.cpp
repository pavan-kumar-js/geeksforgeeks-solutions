#include <iostream>

int largestpairSum( int *numbersList, int size){

    int largest = numbersList[0];
    int secondLargest = numbersList[0];
    if( size <= 0 ){
        return -1;
    }

    int index;
    for( index = 1; index < size ; index++){
        if(secondLargest < numbersList[index]){
            if(largest < numbersList[index]){
                secondLargest = largest;
                largest = numbersList[index];
            }
            else{
                secondLargest = numbersList[index];
            }

        }
    }

    return largest+secondLargest;
}

int main(){
    
    int arr[] = {12, 34, 10, 6, 40} ;
    int largeSum = largestpairSum(arr,5);
    
    printf("%d is the largest sum",largeSum);
    
    return 0;
}