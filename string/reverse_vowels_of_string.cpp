#include<iostream>
using namespace std;

bool isVowel(char s){
    if (s == 'a'|| s == 'e'|| s == 'o'|| s == 'i'|| s == 'u'|| s == 'A'|| s == 'E'|| s == 'O'|| s == 'I'|| s == 'U')
        return true;

    return false;
}

string reverseVowels(string s) {
    int n = s.length();
    int start = 0;
    int end = n-1;

    while(start < end){
        while(start < n && !isVowel(s[start]))
            start++;
    
        while(end > start && !isVowel(s[end]))
            end--;

        if (start < end)
            swap(s[start++], s[end--]);
    }
    return s;
}

int main(){
    
    string s;
    cout << "Enter a string: ";
    cin >> s;

    s = reverseVowels(s);

    cout << s;

    return 0;
}