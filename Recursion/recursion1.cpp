#include<iostream>
using namespace std;

// This program calculates 2 raised to the power of n using recursion.

int power(int n){

    if(n == 0)
        return 1;

    return 2 * power(n-1);
}

int main(){

    int a = 0;
    cout << "Enter a number: ";
    cin >> a;

    cout << power(a);     

    return 0;
}