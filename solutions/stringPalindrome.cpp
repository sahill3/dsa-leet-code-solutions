#include<iostream>
using namespace std;


int length(string s){
    int count = 0, i = 0;
    while(s[i] != '\0'){
        count++;
        i++;
    }
    return count;
}

bool isPalindrome(string s) {
    int a = 0;
    int n = length(s) - 1;

    while(a <= n){
        if(!isalpha(s[a])){
            a++;
            continue;
        }

        if(!isalpha(s[n])){
            n--;
            continue;
        }

        cout << s[a] << " " << s[n] << endl;
        if(tolower(s[a]) != tolower(s[n])){
            return false;
        }
        else{
            a++;
            n--;
        }
    }
    return true;
}


int main(){
    
    string s = "race a car";
    cout << isPalindrome(s);
    return 0;
}