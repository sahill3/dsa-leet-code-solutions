#include<iostream>
#include<string>
#include<vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> hash(256,0);
    int ans = 0;
    int l = 0, r = 0;

    while(r < s.length()){
        hash[s[r]]++;

        while(hash[s[r]] > 1 &&  l <= r)
            hash[s[l++]]--;

        ans = max(ans, (r-l+1));
        r++;
    }
    return ans;
}

int main(){

    string s = "cbb";
    string c = "pwwkew";

    cout << lengthOfLongestSubstring(s) << endl;
    cout << lengthOfLongestSubstring(c) << endl;
    
    return 0;
}