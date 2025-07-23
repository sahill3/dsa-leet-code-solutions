#include<iostream>
#include<vector>
using namespace std;

void rec(int index, int sum, vector<int> &ans, vector<int> &nums){
    if (index == nums.size()){
        ans.push_back(sum);
        return;
    }

    rec(index+1, sum, ans, nums);
    rec(index+1, sum+nums[index], ans, nums);
}

int main(){
    
    vector<int> ans;
    int sum = 0, index = 0;
    vector<int> nums = {2, 3};

    rec(index, sum, ans, nums);
    
    for (int i: ans)
        cout << i << " ";

    return 0;
}