#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

/* MY SOLUTION
string gcdOfStrings(string str1, string str2) {
    string ans = "";
    string sub = "";
    string s;
    string l;

    if (str1.length() > str2.length()){
        s = str2;
        l = str1;
    }
    else{
        s = str1;
        l = str2;
    }
    
    for (int i = 0; i < s.length(); i++){
        if (s[i] == l[i]){
            sub += s[i];
        }
        else
            return "";

        int n = sub.length();
        int flag = true;
        for (int j = 0; j < s.length(); j+=n){
            if (sub != s.substr(j, n)){
                flag = false;
                break;
            }
        }

        for (int j = 0; j < l.length(); j+=n){
            if (sub != l.substr(j, n)){
                flag = false;
                break;
            }
        }

        if (flag)
            ans = sub;
    }
    return ans;
}
*/

//OPTIMAL SOLUTION
string gcdOfStrings(string str1, string str2) {
    return (str1 + str2 == str2 + str1)? 
    str1.substr(0, __gcd(str1.size(),str2.size())): "";
}


int main(){
    
    string s;
    string l;

    cout << "Enter string 1: ";
    cin >> s;
    
    cout << "Enter string 2: ";
    cin >> l;

    string ans = gcdOfStrings(s, l);

    
    cout << "GCD: " << ans;

    return 0;
}