#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        set<int> s(nums.begin(), nums.end());
        vector<int> t(s.begin(), s.end());

        int cnt = 0;
        int ans = 0;

        for(int i = 0; i < t.size() - 1; i++){
            if(t[i+1] - t[i] == 1) { 
                cnt++; 
            }
            else {
                if(cnt > ans){
                    ans = cnt;
                    cnt = 0;
                }
                else
                    cnt = 0;
            }
        }
        return cnt>ans? cnt+1 : ans+1;
}

int main(){
    
    vector<int> nums {100,4,200,1,3,2};
    int k = longestConsecutive(nums);
    cout << k << endl;
    return 0;
}