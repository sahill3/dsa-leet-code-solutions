#include<iostream>
#include<string>
using namespace std;
int main(){
    string s2 = "eidbaooo";
    int l  = 0, r = 2;
    while(r < s2.size()){
        string temp(s2.begin()+l, s2.begin()+r);
        cout << temp << endl;
        l++;
        r++;
    }
    
    
    return 0;
}