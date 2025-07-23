#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> &arr, int target, vector<int> &ds, vector<vector<int>> &ans, int index) {
    if (index == arr.size()){
        if (target == 0){
            ans.push_back(ds);
        }
        return;
    }

    if (target >= arr[index]){
        ds.push_back(arr[index]);
        solve(arr, target-arr[index], ds, ans, index);
        ds.pop_back();
    }

    solve(arr, target, ds, ans, index+1);
    return;
}

int main(){
    
    vector<int> arr = {4, 3, 6, 7};
    vector<int> ds;
    vector<vector<int>> ans;
    int target = 7;

    solve(arr, target, ds, ans, 0);

    for (auto& ar: ans){
        for (int i: ar) cout << i << " ";
        cout << endl;
    }

    return 0;
}
