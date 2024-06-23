#include<iostream>
using namespace std;

int mod(int a, int b){
    int k = 0;

    while(a - b*k >= b) ++k;

    return a - k*b;
}

int main(){

    cout << mod(9, 3);
   
    return 0;
}