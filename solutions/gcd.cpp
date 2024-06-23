#include<iostream>
using namespace std;

int gcd(int x, int y){
    
    if(x == 0)
    return y;

    if(y == 0)
    return x;

    while(x != y){
        
        if(x>y){
            x = x - y;
        }
        else{
            y = y - x;
        }
    }
    return x;
}

int main(){
    
    int a, b;
    cout << "Enter 2 numbers whose Greatest Common Divisor is to be calculated: ";
    cin >> a;
    cin >> b;

    int ans = gcd(a, b);

    cout << ans;

    return 0;
}