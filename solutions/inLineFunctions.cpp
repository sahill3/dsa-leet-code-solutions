#include<iostream>
using namespace std;

inline int getMax(int a, int b){
    return (a>b) ? a : b;
}

int main(){
    
    int a = 10;
    int b = 13;

    int ans = getMax(a, b);
    
    cout << ans;

    return 0;
}