//2133. Check if Every Row and Column Contains All Numbers

//An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

//Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> rowMask(n, 0), colMask(n, 0);
        int fullMask = (1 << n) - 1;  // all n bits set

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = matrix[i][j] - 1;

                int bit = 1 << d;

                if (rowMask[i] & bit) return false;
                if (colMask[j] & bit) return false;

                rowMask[i] |= bit;
                colMask[j] |= bit;
            }
        }

        for (int i = 0; i < n; i++) {
            if (rowMask[i] != fullMask || colMask[i] != fullMask)
                return false;
        }

        return true;
    }
};

int main(){
     
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {3, 1, 2}, {2, 3, 1}};
    bool result = sol.checkValid(matrix);
    return 0;
}

