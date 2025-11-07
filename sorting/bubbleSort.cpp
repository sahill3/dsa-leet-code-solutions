#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();

    for(int i = 0; i < n-1; i++){
        bool swapped = false;
        for(int j = 0; j < n-1-i; j++){
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }   
        if (!swapped) return;
    }
}

int main(){
    
    vector<int> arr = {13, 46, 24, 52,  20, 9};

    bubbleSort(arr);

    for (int i: arr){
        cout << i << " ";
    }

    return 0;
}