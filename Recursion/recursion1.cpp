#include<iostream>
using namespace std;

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