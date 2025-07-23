#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void solve(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int target, int index){
    if (target == 0){
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < arr.size(); i++){
        if (i > index && arr[i] == arr[i-1]) continue;
        if (arr[i] > target) break;
        ds.push_back(arr[i]);
        solve(arr, ds, ans, target - arr[i], i+1);
        ds.pop_back();
    }    

    return;
}

int main(){
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};  
    vector<int> ds;
    vector<vector<int>> ans;
    int target = 8;

    sort(arr.begin(), arr.end());

    solve(arr, ds, ans, target, 0);

    for (auto& ar: ans){
        for (int i: ar) cout << i << " ";
        cout << endl;
    }

    return 0;
}