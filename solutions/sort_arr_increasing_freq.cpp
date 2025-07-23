#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
    map<int, int> mp;
    vector<pair<int, int>> freq;

    for (int i: nums)
        mp[i]++;

    for (auto i: mp)
        freq.push_back(i);

    sort(freq.begin(), freq.end(), [](const pair<int, int> a, const pair<int, int> b){return (a.second == b.second) ? a.first > b.first: a.second < b.second;});

    vector<int> ans;

    for (auto item: freq)
        for (int i = 0; i < item.second; i++) ans.push_back(item.first);

    return ans;
}

int main(){

    vector<int> nums = {2,3,1,3,2};

    vector<int> ans = frequencySort(nums);

    for (int i: ans)
        cout << i << " ";
    
    return 0;
}