#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class comp{
    int param;
public:
    comp (int p) : param(p){}

    bool operator() (vector<int> &a, vector<int> &b){
        return a[param] > b[param];
    }
};


vector<vector<int>> sortbykth(vector<vector<int>>& score, int k) {
    sort(score.begin(), score.end(), comp(k));

    return score;
}


int main(){

    vector<vector<int>> score {{10,6,9,1},
                               {7,5,11,2},
                               {4,8,3,15}};
    
    score = sortbykth(score, 2);

    for (auto arr: score){
        for (int i: arr)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}