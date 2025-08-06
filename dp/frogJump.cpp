//https://www.geeksforgeeks.org/problems/geek-jump/1

#include<iostream>
#include<vector>
using namespace std;

/*
=== Memoization ===
int rec(vector<int> &height, int n, vector<int> &dp){
    if (n < 1) return 0;
    
    if (dp[n] != -1) return dp[n];
    
    int left, right;
    
    left = rec(height, n-1, dp) + abs(height[n] - height[n-1]);
    
    if (n > 1) right = rec(height, n-2, dp) + abs(height[n] - height[n-2]);
    else right = INT_MAX;
    
    return dp[n] = min(left, right);
}
*/

int main(){
    
    vector<int> stairs = {30, 20, 50, 10, 40};
    const int n = stairs.size();
    
    if (n <= 1) cout << 0;
    else{

        int prev = 0;
        int curr = abs(stairs[0] - stairs[1]);
        
        for (int i = 2; i < n; i++){
            int temp = min(abs(stairs[i-1] - stairs[i]) + curr, abs(stairs[i-2] - stairs[i]) + prev);
            prev = curr;
            curr = temp;
        }   
        cout << curr;
    }
    return 0;
}