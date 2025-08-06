#include<iostream>
#include<vector>
using namespace std;

/*
=== Memoization ===
Time: O(n)
Space: O(n) + O(n)
*/

int rec(int n, vector<int> &arr, vector<int> &dp){
    if (dp[n] != -1) return dp[n];
    
    if (n == 0) return dp[n] = arr[n];

    if (n < 0) return 0;

    int pick = arr[n] + rec(n-2, arr, dp);
    int not_pick = rec(n-1, arr, dp);

    return dp[n] = max(pick, not_pick);
}

int main(){
    
    vector<int> arr = {2, 1, 4, 9};

    int n = arr.size();

    // vector<int> dp (n, -1);

    // int ans = rec(n-1, arr, dp);

    /*
    === Tabulization ===
    Time: O(n)
    Space: O(n) + O(n)
    
    vector<int> dp (n, 0);
    dp[0] = arr[0];
    
    for (int i = 1; i < n; i++){
        int pick = arr[i];
        if (i > 1) pick += (dp[i-2]);
        int notPick = dp[i-1];
        
        dp[i] = max(pick, notPick);
    }
    cout << dp[n-1];
    */

    /*
    === Space Optimizzed ===
    Time: O(n)
    Space: O(n)
    */
    int prev = 0, curr = arr[0];
    
    for (int i = 1; i < n; i++){
        int pick = arr[i];
        if (i > 1) pick += prev;
        int notPick = curr;

        int temp = max(pick, notPick);
        prev = curr;
        curr = temp;
    }
    cout << curr;

    return 0;
}