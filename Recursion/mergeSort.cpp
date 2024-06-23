#include<iostream>
using namespace std;

void merge(int* arr, int start, int mid, int end, int* temp){
    int i = start;
    int j = mid+1;
    int k = start;

    while(i <= mid && j <= end){
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= end)
        temp[k++] = arr[j++];

    for(int p = start; p <= end; p++)
        arr[p] = temp[p];
}

void mergeSort(int* arr, int start, int end, int* temp){
    if(start >= end)
        return;

    int mid = start + (end-start)/2;

    mergeSort(arr, start, mid, temp);
    mergeSort(arr, mid+1, end, temp);

    merge(arr, start, mid, end, temp);
}

int main(){
    

    int arr[5] = {4, 5, 1, 3, 2};
    int size = 5;
    int temp[5];

    mergeSort(arr, 0, size-1, temp);

    for(int i: arr)
        cout<<i<<" ";

    return 0;
}