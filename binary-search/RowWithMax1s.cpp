// Row with max 1s

#include<iostream>
#include<vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> &mat) {
    int maxi = 0, index = -1;
    int col = mat[0].size();
    for(int row = 0; row < mat.size(); row++){
        int l = 0, r = col-1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if (mat[row][mid] == 1) r = mid - 1;
            else l = mid + 1;
        }
        int sum = col - l;
        if (sum > maxi){
            maxi = sum;
            index = row;
        }
    }
    return index;
}

int main(){
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1}
    };
    cout << "Row with maximum 1s is: " << rowWithMax1s(mat) << endl;
    return 0;
}