#include<iostream>
#include<cstring>
using namespace std;

int fibo(int n, int dp[]){
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    return dp[n];
}

int main(){
    const int n = 5;

    int dp[n+1];
    memset(dp, -1, sizeof dp);

    cout << fibo(n, dp) << endl;
    
    int s = 0, l = 1;

    for (int i = 0; i < n-1; i++){
        int temp = s + l;
        s = l;
        l = temp;
    }

    cout << l;

    return 0;
}