#include<iostream>
using namespace std;

/*
The Golomb sequence is a non-decreasing integer sequence in which the n-th term equals the number of times the letter n appears in the sequence. 
The first few numbers are 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5,......
*/

int dp[1000];

void findGolomb(int N)
{
    // Base case
    dp[1] = 1;
 
    // Calculating the first N terms of the Golomb Sequence.
    for (int i = 2; i <= N; i++){
        dp[i] = 1 + dp[i - dp[dp[i - 1]]];
    }
}

int main(){
    int N = 11;
    findGolomb(N);
    
    // Output the sequence
    for (int i = 1; i <= N; i++)
        cout << dp[i] << " ";
    
    return 0;
}
