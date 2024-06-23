#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int val){
    if (st.empty()){
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    solve(st, val);
    st.push(temp);
}

int main(){
      
    int val = 0;

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    solve(st, val);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}