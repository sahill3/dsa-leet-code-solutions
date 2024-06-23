#include<iostream>
using namespace std;

int fact(int a){
    if(a <= 1){
        return 1;  //once the value of a becomes 1, the function returns 1 and pointer goes to main block
    }
    return a * fact(a-1);
}

int main(){
    int a;
    cout<<"Enter a number: ";
    cin>>a;
    cout<<"The factorial of "<<a<<" is "<<fact(a);
    return 0;
}