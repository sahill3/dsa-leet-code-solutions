#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &st, int temp){

    if (st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }

    int ele = st.top();
    st.pop();

    insert(st, temp);
    
    st.push(ele);
}

void sort(stack<int> &st){
    if (st.empty())
        return;

    int temp = st.top();
    st.pop();

    sort(st);

    insert(st, temp);
}

void print(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){

    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(9);
    st.push(6);
    st.push(1);

    print(st);

    sort(st);

    print(st);
    
    return 0;
}