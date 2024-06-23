#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int size, int cnt){
    if (cnt == 0){
        st.pop();
        return;
    }

    int temp = st.top();
    st.pop();
    solve(st, size, cnt-1);
    st.push(temp);
}

int main(){

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    solve(st, st.size(), st.size() / 2);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}