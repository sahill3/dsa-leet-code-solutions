#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> st;

    int num = 1098;
    int i = 1;

    
    while(num){
        st.push(num % 10);
        num /= 10;
    }

    while(!st.empty()){
        num += st.top() * i;
        st.pop();
        i *= 10;
    }

    cout << "\n" << num;

    return 0;
}