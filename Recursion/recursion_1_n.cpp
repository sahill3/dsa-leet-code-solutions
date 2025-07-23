#include<iostream>
using namespace std;

void rec(int n){
    if (n <= 0) return;

    rec(n - 1);

    cout << n << endl;
}

int main(){
    
    int n;
    
    cout << "Enter a number: ";
    cin >> n;

    rec(n);

    return 0;
}