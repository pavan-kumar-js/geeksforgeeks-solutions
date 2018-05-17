


#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int i, int n){

    int largest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    swap(&arr[i],&arr[largest]);

    if(largest != i){

        heapify(arr, largest,n);

    }
 }

 void print_array(int *arr, int n){
    for(int i=0;i<6;i++){
    printf("%d ",arr[i]);
    }
    printf("\n");
    }
int main()
{
    int arr[] = {1,6,5,3,2,9};

    print_array(arr,6);

    int n=6;
    int k = 0;
    for(int j=5;j>=0;j--){
        for(int i=2;i>=0;i--){
            heapify(arr,i,n - k);
        }
        swap(&arr[0],&arr[j]);
        k++;
    }


    print_array(arr,6);

    return 0;
}