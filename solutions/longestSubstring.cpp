#include<iostream>
using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    int count = -1;
        
    for(int i = 0; i < s.length(); i++){
        for(int j = s.length() - 1; j > i; j--){
            if(i == j)
                return ++count;
            else{
                if(s[i] == s[j]){
                    for(int k = i; k < j; k++){
                        count++;
                        cout << count;
                    }
                    return count;
                }
            }
        }
    }
    return count;
}

int main(){
    
    int ans = maxLengthBetweenEqualCharacters("aa");
    cout << ans ;
    return 0;
}