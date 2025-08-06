#include<iostream>
#include<vector>
using namespace std;

/* 
=== Recursive Method ===
Slowest
Time: O(2^n)
Space: O(n)

int climb(int n, vector<int> &cost){
    if (n < 2) return 0;
    
    return min(cost[n-1] + climb(n-1, cost),
    cost[n-2] + climb(n-2, cost));
}
*/

/* 
=== Memoization ===
TOP DOWN
Fast but not space optimized
Time: O()
Space: O()

int climb(int n, vector<int> &cost, vector<int> &dp){
    if (n < 2) return 0;
    
    if (dp[n] != -1) return dp[n];
    
    return dp[n] = min(cost[n-1] + climb(n-1, cost, dp),
    cost[n-2] + climb(n-2, cost, dp));
}
*/

/* 
=== Tabulation ===
Bottom Up
Fastest and space optimized
Time: O(n)
Space: O(n)
*/

int climb(int n, vector<int> &cost){
    int prev = 0;
    int curr = 0;

    for (int i = 2; i < n+1; i++){
        int temp = min((curr + cost[i-1]), (prev + cost[i-2]));
        prev = curr;
        curr = temp;
    }
    
    return curr;
}

int main(){
    vector<vector<int>> tests = {
        {10, 15, 20},
        {1,100,1,1,1,100,1,1,100,1}
    };

    for (auto ele: tests){
        int n = ele.size();
        vector<int> dp (n+1, -1);
        cout << climb(n, ele) << endl;
    }
    return 0;
}