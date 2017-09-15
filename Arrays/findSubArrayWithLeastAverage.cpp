#include<iostream>

int findSubArrayLeastAverage (int *arr, size_t size, int k){

    int index1 = 0, index2 = 0;
    int result1 = -1;
    int result2 = -1;
    int leastSum = 0;
    while(k){
        leastSum+=arr[index2];
        index2++;
        k--;
    }
    int currentSum = leastSum;
    for(index1++,index2;index2<size;index1++,index2++){
        currentSum -= arr[index1-1];
        currentSum += arr[index2];
        if(currentSum < leastSum){
            leastSum = currentSum;
            result1 = index1;
            result2 = index2;
        }
    }

    printf("Least average lies between %d and %d", result1,result2);

    return 0;
}

int main(){

    int arr[] = {3, 7, 5, 20, -10, 0, 12};
    int k = 2;
    size_t size = 7;

    findSubArrayLeastAverage(arr,size,k);

}