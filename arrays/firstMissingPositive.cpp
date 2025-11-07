// Hard

#include<iostream>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();

        for(int i = 0; i < len; i++){
            int ele = nums[i];

            if (ele >= 1 && ele <= len){
                int chair = ele - 1;
                if (nums[chair] != ele){
                    swap(nums[i], nums[chair]);
                    i--;
                }
            }
        }

        for(int i = 0; i < len; i++){
            if (nums[i] != i+1) return i + 1;
        }
        return 0;
    }

int main(){
    vector<int> nums = {3, 4, -1, 1};
    cout << firstMissingPositive(nums) << endl;  
    return 0;
}