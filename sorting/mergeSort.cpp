#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end, vector<int> &temp){

    int i = start, j = mid + 1, ind = start;

    while(i <= mid && j <= end){
        if (arr[i] < arr[j])
            temp[ind++] = arr[i++];
        else
            temp[ind++] = arr[j++];
    }

    while(i <= mid)
        temp[ind++] = arr[i++];
    while(j <= end)
        temp[ind++] = arr[j++];
    
    for(i = start; i < end+1; i++)
        arr[i] = temp[i];

}

void mergeSort(vector<int> &arr, int start, int end, vector<int> &temp){

    if (start >= end)
        return;

    int mid = (start + end) >> 1;

    mergeSort(arr, start, mid, temp);
    mergeSort(arr, mid + 1, end, temp);

    merge(arr, start, mid, end, temp);

}


int main(){
    
    vector<int> arr = {13, 46, 24, 52,  20, 9};

    vector<int> temp (arr.size());

    mergeSort(arr, 0, arr.size()-1, temp);

    for (int i: arr){
        cout << i << " ";
    } 
    
    return 0;
}