#include<iostream>
using namespace std;

void reverse(string &s, int i){
    if(i >= s.length()-1-i)
        return ;
    else{
        swap(s[i], s[s.length()-1-i]);
        reverse(s, i+1);
    }
}

int main(){
    
    string str = "selected";
    reverse(str, 0);
    cout << str;

    return 0;
}