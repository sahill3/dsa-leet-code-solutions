#include<iostream>
using namespace std;

bool palindrome(string s, int i){
    if(i >= s.length()-1-i)
        return true;
    else if(s[i] != s[s.length()-1-i])
        return false;
    else
        return palindrome(s, i+1);
}

int main(){
    
    string str = "maam";

    if(palindrome(str, 0))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}