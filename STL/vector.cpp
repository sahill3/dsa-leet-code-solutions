#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> a(2, 1);
    vector<int> clone = a; //clones a vector

    a.capacity();
    a.size();
    a.pop_back();
    a.push_back(2);
    
    for(auto i:a){
        cout<<i<<" ";
    }        

    cout << endl << endl;

    a.clear();
    clone.clear();

    clone.push_back(-1);
    clone.push_back(-100);
    clone.push_back(3);
    clone.push_back(99);
   

    rotate(clone.begin(), clone.begin()+4, clone.end()); 
    int k = 2;
    int r = 2;

    reverse(clone.begin(), clone.end());

    for(auto i: clone){
        cout << i << " " ;
    }

    return 0;

        // vector<int> temp(nums.size());

        // for(int i = 0; i < nums.size(); i++){
        //     temp[(i+k)%nums.size()] = nums[i];
        // }
        // nums = temp;
}