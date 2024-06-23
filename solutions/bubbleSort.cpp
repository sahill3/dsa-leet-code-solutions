#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums {100, 5, 2, 0, 1, 9, 4};
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    
    return 0;
}