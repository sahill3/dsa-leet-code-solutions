#include<bits/stdc++.h>
using namespace std;

int poww(int exp, int base){
    int temp = base;
    while(exp-1){
        temp *= base;
        exp--;
    }
    return temp;
}

int main(){
    
    int n = 2;
    int m = 2;
    int temp = m;
    while(n-1){
        temp *= m;
        n--;
    }
    cout << ceil(1/3);

    return 0;
}