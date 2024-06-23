#include<iostream>

using namespace std;
int main(){

    string str = "selected";
    int b = str.length();
    int j = b-1;
    for(int i = 0; i < b/2; i++){
        swap(str[i], str[j]);
        j-= 1;
    }

    cout << str;

    return 0;
}