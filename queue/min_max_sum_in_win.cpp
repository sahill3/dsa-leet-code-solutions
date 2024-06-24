#include<iostream>
#include<deque>
#include<vector>

using namespace std;
int main(){

    int k = 4;
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    int i;
    vector<int> ans;

    deque<int> G, S;

    for (i = 0; i < k; i++){
        while (!G.empty() && arr[G.back()] <= arr[i])
            G.pop_back();

        while (!S.empty() && arr[S.back()] >= arr[i])
            S.pop_back();
        
        G.push_back(i);
        S.push_back(i);
    } 

    for ( ; i < len; i++){
        sum = arr[G.front()] + arr[S.front()];

        while (!G.empty() && i - G.front() >= k)
            G.pop_front();
    
        while (!S.empty() && i - S.front() >= k)
            S.pop_front();


        while(!S.empty() && arr[S.back()] >= arr[i])
            S.pop_back();

        while(!G.empty() && arr[G.back()] <= arr[i])
            G.pop_back();

        G.push_back(i);
        S.push_back(i);

        ans.push_back(sum);
    }

    ans.push_back(arr[G.front()] + arr[S.front()]);

    for (auto it:ans)
        cout << it << " ";

    return 0;
}