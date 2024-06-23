#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);


    reverse(v.begin(), v.begin()+4);
    reverse(v.begin()+4, v.end());
    reverse(v.begin(), v.end());

    for(auto i: v){
        cout << i << ' ';
    }
    return 0;
}