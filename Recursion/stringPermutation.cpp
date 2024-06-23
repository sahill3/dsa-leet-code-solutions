#include<iostream>
#include<string>
#include<vector>
using namespace std;

void permutation(vector<int> input, int index, vector<vector<int>>& ans){
    if(index >= input.size()){
        ans.push_back(input);
        return;
    }

    for(int j = index; j < input.size(); j++){      
        swap(input[index], input[j]);
        permutation(input, index + 1, ans);
        swap(input[index], input[j]);
    }
}

int main(){
    vector<int> input = {1, 2, 3, 4};
    vector<vector<int>> ans;
    int index = 0;

    permutation(input, index, ans);

    for(auto &i: ans){
        for (auto &j: i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}