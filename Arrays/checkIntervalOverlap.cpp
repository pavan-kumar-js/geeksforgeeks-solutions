#include <iostream>
struct Interval{
    int first;
    int second;
};

int comparator(const void *i1,const void  *i2){
    int l = ((struct Interval *)i1)->first;
    int r = ((struct Interval *)i2)->first;
    return (l - r);
}
int checkIntervalOverlap(Interval *interval, size_t size){

    int index = 1;

    qsort(interval,size,sizeof(Interval),comparator);

    for ( index; index < size; index++){
        if(interval[index].first < interval[index-1].second){
            return 1;
        }
    }
    return 0;
}

int main(){
    Interval interval[] = {{1,3}, {7,9}, {4,6}, {10,13}};
    size_t size = 4;
    int check = checkIntervalOverlap(interval,size);

    printf("Overlap occurring %d",check);

    return 0;
}