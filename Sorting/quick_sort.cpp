#include<iostream>
#include <time.h>


using namespace std;


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high){

    int l = low-1;
    int r = high +1;
    int pivot = arr[low];

    while(true){

        do{
            l++;
        }while(arr[l] < pivot);


        do{
            r--;
        }while(arr[r] > pivot);

        if(l>=r){
            return r;
        }

        swap(&arr[l],&arr[r]);

    }
}

int partition_r(int *arr, int low,int high){

    srand(time(NULL));

    int random = low + rand()%(high-low);

    swap(&arr[random],&arr[high]);

    return partition(arr,low,high);

}
void quick_sort(int *arr, int low, int high){

    if(low < high){

        int pos = partition_r(arr,low,high);


        quick_sort(arr,low,pos);

        quick_sort(arr,pos+1,high);

    }
}

void print_array(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[] = {10,9,8,7,6,5};

    print_array(arr,6);

    quick_sort(arr,0,5);

    print_array(arr,6);

    return 0;
}