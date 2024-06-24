#include<iostream>
#include<deque>
#include<vector>

using std::cout;
using std::cin;
using std::deque;
using std::vector;

vector<int> printFirstNegativeInteger(int *A, int N, int K) {
    
    vector<int> ans;
    deque<int> q;

    for (int i = 0; i < K; i++){
        if (A[i] < 0)
            q.push_back(i);
    }

    if (q.empty())
        ans.push_back(0);
    else 
        ans.push_back(A[q.front()]);

    for (int i = K; i < N; i++){
        if (!q.empty() && i - q.front() >= K)
            q.pop_front();

        if (A[i] < 0)
            q.push_back(i);

        if (q.empty())
            ans.push_back(0);
        else 
            ans.push_back(A[q.front()]);
    }
    return ans;
}

int main(){

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int* arr = new int[n];

    cout << "Enter the numbers: " << "\n";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;

    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> ans = printFirstNegativeInteger(arr, n, k);

    cout << "Answer: ";
    for (auto it: ans) cout << it << " ";

    return 0;
}