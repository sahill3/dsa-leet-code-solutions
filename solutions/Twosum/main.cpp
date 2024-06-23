#include<iostream>

using namespace std;

int sumtwo(const int arr[], int target, int size){
    for (int i = 0; i < size; i++){
        for(int j = size-1; j >= 0; j--){
            if(arr[i] + arr[j] == target){
                cout << i <<" "<<j;
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int nums[] = {2, 7, 11, 15};
    int target = 9;


    sumtwo(nums, target, sizeof(nums)/sizeof(nums[0]));
    return 0;
}