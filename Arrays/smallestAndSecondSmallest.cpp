#include<iostream>

using namespace std;

int smallestAndSecondSmallest(int *numbersList, int n,int *smallest,int *secondSmallest){

    if( n <= 0 ){
        *smallest = -1;
        *secondSmallest = -1;
        return 0;
    }

    int index;
    *smallest = numbersList[0];
    *secondSmallest = numbersList[0];
    for( index = 0; index < n ; index++){
        if(*secondSmallest > numbersList[index]){
            if(*smallest > numbersList[index]){
                *secondSmallest = *smallest;
                *smallest = numbersList[index];
            }
            else{
                *secondSmallest = numbersList[index];
            }

        }
    }

    return 0;
}
int main() {

    int numbers[] = {5,11,6,2,9,21,16};
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    smallestAndSecondSmallest(numbers,7,&smallest,&secondSmallest);
    printf("smallest and second smallest numbers in the list are %d and %d",smallest,secondSmallest);
    return 0;
}