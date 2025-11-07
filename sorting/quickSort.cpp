#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int> &arr, int start, int end){

    if (start >= end) return;

    int pivot = arr[start];

    int count = 0;

    for(int i = start+1; i  <= end; i++)
        if (arr[i] <= pivot) count++;

    swap(arr[start], arr[start + count]);

    int l = start + count - 1;
    int r = start + count + 1;

    while(l >= start && r <= end){
        while(l >= start && arr[l] < pivot) l--;

        while(r <= end && arr[r] >= pivot) r++;
        
        if (l >= start && r <= end) swap(arr[l--], arr[r++]);
    }

    quickSort(arr, start, start + count - 1);
    quickSort(arr, start + count + 1, end);
}

int main(){
    
    // vector<int> arr = {13, 46, 24, 52,  20, 9};
    vector<int> arr = {4, 2, 2, 4, 3};

    quickSort(arr, 0, arr.size()-1);

    for (int i: arr){
        cout << i << " ";
    }
    
    return 0;
}