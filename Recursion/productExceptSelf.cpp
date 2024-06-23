#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums {2, 4, 3};
    int n = nums.size()-1;
    vector<int> ans(n+1);
    
    for(int i = 0; i <= n; i++){
        int s = i-1, e = i+1;
        int p1 = 1;
        while(s >= 0)
            p1 *= nums[s--];
        
        while(e <= n)
            p1 *= nums[e++];

        ans[i] = p1;
    }
    
    for(int i: ans){
        cout << i << " ";
    }

    return 0;
}