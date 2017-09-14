#include<iostream>

int printUnion( int *arr1, int size1, int *arr2, int size2){

    int index1 = 0, index2 = 0;
    printf("Union of the arrays : ");
    while(index1 < size1 && index2 < size2){
        if(arr1[index1] == arr2[index2]){
            printf("%d ",arr1[index1]);
            index1++;
            index2++;
        }
        else if(arr1[index1] < arr2[index2]){
            printf("%d ",arr1[index1]);
            index1++;
        }
        else{
            printf("%d ",arr2[index2]);
            index2++;
        }
    }

    while(index1 < size1 ){
            printf("%d ",arr1[index1]);
            index1++;
        }

    while(index2 < size2 ){
        printf("%d ",arr2[index2]);
        index2++;
    }

    printf("\n");
    return 0;

}

int printIntersection(const int *arr1, int size1,const int *arr2, int size2){

    int index1 = 0, index2 = 0;
    printf("Intersection of the arrays : ");
    while(index1 < size1 && index2 < size2){
        if(arr1[index1] == arr2[index2]){
            printf("%d ",arr1[index1]);
            index1++;
            index2++;
        }
        else if(arr1[index1] < arr2[index2]){
            index1++;
        }
        else{
            index2++;
        }
    }

    printf("\n");
    return 0;
}

int main(){

    int arr1[] = {1, 3, 4, 5, 7};
    int arr2[] = {2, 3, 5, 6};

    printUnion(arr1,5,arr2,4);
    printIntersection(arr1,5,arr2,4);

    return 0;
}

