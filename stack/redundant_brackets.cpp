#include<iostream>
#include<stack>
using namespace std;

bool solve(string s){
    stack<char> st;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            st.push(s[i]);
        else if(s[i] == ')'){
            //check if stack has an operator
            bool flag = false;
            while(st.top() != '('){
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                    flag = true;
                
                st.pop();
            }
            st.pop();
            if (!flag)
                return false; 
        }
    }
    return true;
}

int main(){

    string s = "((c/d)+a*b)";

    stack<char> st;

    bool ans = solve(s);    

    if (ans)
        cout << "No redundant brackets.";
    else 
        cout << "Redundant brackets found.";

    return 0;
}