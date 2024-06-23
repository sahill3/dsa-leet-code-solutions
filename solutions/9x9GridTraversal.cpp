#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++){
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int j = 0; j < 9; j++){
            if(board[i][j] != '.') {mp1[board[i][j]]++;}
            if(board[j][i] != '.') {mp2[board[j][i]]++;}
        }
        for(auto s:mp1){
            if(s.second > 1)
                return false;
        }

        for(auto s:mp2){
            if(s.second > 1)
                return false;
        }
    }
    
    int ce = 3;
    int cs = 0;
    int rs = 0;
    int re = 3;
    for(int m = 0; m < 3; m++){
        for(int n = 0; n < 3; n++){
            unordered_map<char, int> mp;
            for(int i = rs; i < re; i++){
                for(int j = cs; j < ce; j++){
                    if(board[i][j] != '.') {mp[board[i][j]]++;}
                }
            }
            for(auto s:mp){
                if(s.second > 1)
                    return false;
            }
            cs += 3;
            ce += 3;
        }
        cs = 0;
        ce = 3;
        rs += 3;
        re += 3;
    }
    return true;
}


int main(){
    
    int grid[9][9] = {{1, 1, 1, 2, 2, 2, 3, 3, 3},
                      {1, 1, 1, 2, 2, 2, 3, 3, 3},
                      {1, 1, 1, 2, 2, 2, 3, 3, 3},
                      {4, 4, 4, 5, 5, 5, 6, 6, 6},
                      {4, 4, 4, 5, 5, 5, 6, 6, 6},
                      {4, 4, 4, 5, 5, 5, 6, 6, 6},
                      {7, 7, 7, 8, 8, 8, 9, 9, 9},
                      {7, 7, 7, 8, 8, 8, 9, 9, 9},
                      {7, 7, 7, 8, 8, 8, 9, 9, 9}};

    cout << isValidSudoku()

    return 0;
}