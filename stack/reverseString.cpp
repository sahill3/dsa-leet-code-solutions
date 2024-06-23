#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str = "spaces";
    stack<int> st;
    
    for (auto &i: str)
        st.push(i);

    string ans = "";

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    cout << str << endl;
    cout << ans << endl;
    return 0;
}