#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();

    for (int i = 0; i < n; i++){
        int mini = i;
        for(int j = i; j < n; j++){
            if (arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

int main(){
    vector<int> arr = {13, 46, 24, 52,  20, 9};

    selectionSort(arr);

    for (int i: arr){
        cout << i << " ";
    }

    return 0;
}