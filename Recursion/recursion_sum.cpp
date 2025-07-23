#include<iostream>
using namespace std;

int rec(int n) {
    if (n == 0){
        return 0;
    }

    return n + rec(n - 1);
}

int main(){
    
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int ans = rec(n);

    cout << ans;
    return 0;
}