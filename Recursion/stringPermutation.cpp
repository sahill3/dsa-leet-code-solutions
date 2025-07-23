#include<iostream>
#include<string>
#include<vector>
using namespace std;

void rec(int index, vector<int> &nums, vector<vector<int>> &ans){
    if (index == nums.size()){
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++){
        swap(nums[i], nums[index]);
        rec(index+1, nums, ans);
        swap(nums[i], nums[index]);
    }
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    int index = 0;

    rec(index, nums, ans);

    for (auto vec: ans){
        for (auto ele: vec) cout << ele << " ";
        cout << endl;
    }

    return 0;
}