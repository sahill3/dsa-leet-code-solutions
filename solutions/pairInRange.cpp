#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pairs(int n, vector<int> arr, int l, int r){
    l = l-1;
    r = r+1;
    int ans = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (arr[i]+arr[j] > l && arr[i]+arr[j] < r)
                ans++;
        }
    }
    return ans;
}

int main(){
    

    vector<int> arr = {2,3,4,5};

    cout << pairs(4, arr, 5, 7);
    
    return 0;
}