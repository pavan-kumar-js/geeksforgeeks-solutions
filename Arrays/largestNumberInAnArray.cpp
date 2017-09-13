#include <iostream>


// Finding largest element in an unsorted array
using namespace std;

int largestElement(int *numbersList, int n){

    if( n <= 0 ){
        return -1;
    }

    int index;
    int largestNumber = numbersList[0];

    for( index = 0; index < n ; index++){
        if(largestNumber < numbersList[index]){
            largestNumber = numbersList[index];
        }
    }

    return largestNumber;
}
int main() {

    int numbers[] = {5,11,6,2,9,21,16};
    printf("Largest number in the list is %d",largestElement(numbers,7));
    return 0;
}