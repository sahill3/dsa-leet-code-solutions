#include<iostream>
#include<string>
using namespace std;

bool valid(){

}

int main(){
    
    char arr[26] = {0};
    string s = "ssaahill";

    int max = -1, ans = 0;

    for( int i = 0; i < s.length(); i++ ){
        
        char ch = s[i];
        int number = ch - 'a';
        arr[number]++;
    }

    for( int i = 0; i < 26; i++){
        if (max < arr[i]){
            max = arr[i];
            ans = i;
        }
    }

    char temp = ans + 'a';
    cout << temp;
    return ans + 'a'; 
}