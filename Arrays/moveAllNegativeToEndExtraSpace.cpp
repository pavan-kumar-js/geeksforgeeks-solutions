#include<iostream>

int moveAllNegativesToEnd(int *arr, int n){

    int index = 0,index2 = 0;
    int *temp = (int *)malloc(sizeof(int)*n);

    for(index; index < n; index++){
        if(arr[index] < 0){
            temp[index2++] = arr[index];
            arr[index] = 0;
        }
    }
    index = 0;
    int sampleIndex = 0;
    int end = n;
    while(index < end){
        if(arr[index] == 0){
            index++;
            continue;
        }
        arr[sampleIndex ++] = arr[index++];
    }
    while(sampleIndex < end){
        arr[sampleIndex++] = 0;
    }
    index = n-1;
    index2--;
    while(index2 >= 0){
        arr[index--] = temp[index2--];
    }
    return 0;
}

void printArray(int *arr, int n){
    int index = 0;

    for (index=0; index < n; index++){
        printf("%d ",arr[index]);
    }

    printf("\n");
}

int main(){

    int arr[] = {-5, 7, -3, -4, 9, 10, -1, 11};
    printArray(arr,8);
    moveAllNegativesToEnd(arr,8);
    printArray(arr,8);
    return 0;
}
