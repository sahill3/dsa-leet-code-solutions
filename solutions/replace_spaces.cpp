#include<iostream>
#include<string>

using namespace std;
int main(){

    string str = "My name is Sam.";
    string ans;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else    
            ans.push_back(str[i]);
    }  

    cout << "Entered string: " << str << endl;  
    cout << "Answer string: " << ans << endl;
  
    return 0;
}