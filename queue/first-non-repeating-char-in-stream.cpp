#include<iostream>
#include<unordered_map>
#include<queue>
#include<string>

using std::cout;
using std::cin;
using std::string;
using std::unordered_map;
using std::queue;

string FirstNonRepeating(string A){
    unordered_map<char, int> mp;
    queue<char> q;
    int N = A.length();
    string ans = "";
    
    for (int i = 0; i < N; i++){
        q.push(A[i]);
        mp[A[i]]++;
        
        while(!q.empty() && mp[q.front()] > 1)
            q.pop();
            
        if (q.empty())
            ans.push_back('#');
        else
            ans.push_back(q.front());
            
    }
    return ans;
}

int main(){
    string A;
    cout << "Enter a string: ";
    cin >> A;

    string ans = FirstNonRepeating(A);
    cout << ans << "\n";

    return 0;
}