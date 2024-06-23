#include<iostream>
using namespace std;

int findPivot(int *arr, int start, int end){
    int mid = start + (end - start)/2;

    if (start >= end)
        return start;

    if (arr[mid] >= arr[0])
        return findPivot(arr, mid + 1, end); 
    else
        return findPivot(arr, start, mid); 
}

int main(){
    
    int *list = new int[5];
    list[0] = 3;
    list[1] = 8;
    list[2] = 10;
    list[3] = 17;
    list[4] = 1;

    cout << findPivot(list, 0, 4);

    delete[] list;
    return 0;
}