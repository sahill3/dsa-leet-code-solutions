#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int val(string s){
        int v = 0;
        for(auto i: s)
            v += (int)i;

        return v;
    }

    bool check(string s, string c){
        if(!s.length())
            return true;

        int cnt = 0;
        for(auto i: s){
            for(auto j: c)
                if(i == j){
                    cnt++;
                    break;
                }    
            }
        return cnt==s.length();
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> space (strs.size(), 0);

        for(int i = 0; i < strs.size(); i++){
            if(space[i] == 1)
                continue;
            vector<string> temp;
            temp.push_back(strs[i]);
            int value = val(strs[i]);
            for(int j = i+1; j < strs.size(); j++){
                int tempVal = val(strs[j]);
                if(tempVal == value && check(strs[j], strs[i])){
                    temp.push_back(strs[j]);
                    space[j] = 1;
                }
            }
            if(temp.size())
                ans.push_back(temp);
        }
        return ans;
    }
};

int main(){
    
    

    return 0;
}