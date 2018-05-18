

#include<iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void print_array(int *arr, int n){
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void merge_sort_helper(int *arr, int low,int high, int mid){

    int n1 = mid-low+1;
    int n2 = high-mid;


    int left_array[n1];
    int right_array[n2];


    for(int i= 0;i < n1 ;i++){
        left_array[i] = arr[low + i];
    }
    for(int i= 0 ;i < n2 ;i++){
        right_array[i] = arr[mid+i+1];
    }

    int k = low;
    int m = 0;
    int n = 0;
    while(m < n1 && n <n2){

        if(left_array[m] <= right_array[n]){
            arr[k] = left_array[m++];
        }
        else {
            arr[k] = right_array[n++];
        }
        k++;
    }

    while(m<n1){
        arr[k++] = left_array[m++];
    }

    while(n< n2){
        arr[k++] = right_array[n++];
    }
}



void merge_sort(int *arr, int low, int high){

    if(low < high){
        int mid = low + (high-low)/2;

        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);

        merge_sort_helper(arr,low,high,mid);
    }
}

int main(){

    int arr[] = {10,8,5,3,1,-1};

    print_array(arr,6);

    merge_sort(arr,0,5);

    print_array(arr,6);

    return 0;
}