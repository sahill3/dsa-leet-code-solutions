#include<iostream>
using namespace std;

int partition(int* arr, int start, int end){
    int pivot = arr[start];
    int cnt = 0;

    for(int i = start+1; i <= end; i++)
        if(arr[i] <= pivot) { cnt++; }

    swap(arr[start], arr[cnt]);
    int pivotIndex = cnt;

    int i = start;
    int j = end;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(int *arr, int start, int end){
    if(start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}

int main(){
    int arr[5] = {6, 7, 1, 6, 5};
    int size = 5;
    int temp[5];

    quickSort(arr, 0, size-1);

    for(int i:arr)
        cout << i << " ";

    return 0;
}