#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int itr = -1;
        vector<vector<int>> ans;
        
        for(int i = 0; i < intervals.size(); i++){
            if (intervals[i][0] < newInterval[0]){
                ans.push_back(intervals[i]);
                if (intervals[i][1] >= newInterval[0]){
                    ans.back()[1] = max(ans.back()[1], newInterval[1]);
                    itr = i + 1;
                    break;
                }
            }
            else{
                ans.push_back(newInterval);
                itr = i;
                break;
            }
        }

        for(int i = itr; i < intervals.size(); i++){
            if (ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }

        if (itr == -1) ans.push_back(newInterval);

        return ans;
    }

int main(){
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> merged = insert(intervals, newInterval);
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}