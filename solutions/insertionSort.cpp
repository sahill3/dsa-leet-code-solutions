#include<iostream>
#include<vector>
using namespace std;

void insertionSort(int n, vector<int> &arr);

int main(){
    vector<int> nums {2, 4, 3, 1, 9, 6, 8};
    int n = nums.size();
    insertionSort(n, nums);

    for(auto i: nums){
        cout << i << " ";
    }
    return 0;
}

void insertionSort(int n, vector<int> &arr){
    int i = 1;
    while(i < n){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
        i++;
    }
}

/*
Why Insertion sort-
-Adaptable - less comparisons initially.
-Stable algo
-Good performace if the n is small and if the array is partially sorted.
*/