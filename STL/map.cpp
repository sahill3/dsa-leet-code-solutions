#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

//stores key value pair
//insert, erase, find, count - O(log n)
//Because map is implemented using Red Black tree or Balanced Tree, the
//complexity of search or find is O(log n).
//Unordered map is implemented using hash tabel, thus has the complexity of search is O(1).

int main(){
    
    // map<int, string> m;
    vector<int> v = {1,2,3,4,5,1};
    unordered_map<int, int> um;
    
    // m[10] = "Slicks";
    // m[20] = "Mediums";
    // m[1] = "hash";
    
    // um.insert({20, "sahil"});
    // um.insert({11, "test"});

    // m.insert({4, "rot"});

    // for(auto i:m){
    //     cout << i.second << endl;
    // }

    // cout << "Is 20 present: " << m.count(20) << endl;

    // m.erase(4);

    // for (auto it: m){
    //     cout << it.first << " :" << it.second << endl;
    // }

    // auto it = m.find(10);

    // for(auto itr = it; itr!=m.end(); itr++){
    //     cout << (*itr).first << endl;
    // }

    // cout << endl;

    // for(auto i : um){
    //     cout << i.first << " :" << i.second << endl;
    // }

    for(auto i:v){
        um[i]++;
    }

    for(auto i : um){
        cout << i.first << " :" << i.second << endl;
    }

    return 0;
}