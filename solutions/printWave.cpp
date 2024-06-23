#include<iostream>
#include<vector>
using namespace std;

void printWave(vector<vector<int>> &wave, int n, int m){

    for(int col = 0; col < m; col++){
        if( col&1 ){
            for(int row = n-1; row >= 0; row--){
                cout << wave[row][col] << " ";
            }
        }
        else{
            for(int row = 0; row < n; row++){
                cout << wave[row][col] << " ";
            }
        }
        cout << endl;
    }
}

int main(){

    vector<vector<int>> wave {{1,4, 6}, {2,5, 9}, {10, 14, 17}};

    int n = wave.size();
    int m = wave[0].size();

    printWave(wave, n, m);
    return 0;
}