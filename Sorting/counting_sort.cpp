#include<iostream>


using namespace std;

void counting_sort(int *arr,int n) {

    int max_ele = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_ele) {
            max_ele = arr[i];
        }
    }


    auto *temp = (int *) calloc(max_ele, sizeof(int));

    for (int i = 0; i < n; i++) {
        temp[arr[i]]++;
    }

    int j = 0;
    for (int i = 0; i < max_ele; i++) {

        while (temp[i]) {

            arr[j++] = i;
            temp[i]--;
        }
    }

}


void print_array(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]= {9,5,4,1,1,6,41};

    print_array(arr,7);

    counting_sort(arr,7);

    print_array(arr,7);
    return 0;
}