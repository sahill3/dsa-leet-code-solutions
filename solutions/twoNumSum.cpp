#include<iostream>

using namespace std;

int sumtwo(int arr[], int target, size_t size){
    for (int i = 0; i < size; i++){
        for(int j = size-1; j >= i; j--){
            if(arr[i] + arr[j] == target){
                cout << i <<" "<<j;
                return 0;
            }
        }
    }
    cout << "No combination found.";
    return 1;
}

int main(){
    int nums[] = {2,7,11,15};
    int target = 21;

    sumtwo(nums, target, sizeof(nums)/sizeof(nums[0]));

    return 0;
}