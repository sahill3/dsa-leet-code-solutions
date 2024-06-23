#include<iostream>
using namespace std;

int steps(int n){
    if(n < 0)
        return 0;
    else if(n == 0)
        return 1;
    else
        return steps(n-1) + steps(n-2);
}

int main(){

    int n = 0;
    cout << "Enter the number of steps: ";
    cin >> n; 

    int ans = steps(n);

    cout <<  ans << " ways to climb the steps.";  

    return 0;
}