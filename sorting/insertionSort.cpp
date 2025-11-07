#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

int main(){
    
    vector<int> arr = {13, 46, 24, 52,  20, 9};

    insertionSort(arr);

    for (int i: arr){
        cout << i << " ";
    }

    return 0;
}