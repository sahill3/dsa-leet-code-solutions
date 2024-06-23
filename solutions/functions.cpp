#include<iostream>
using namespace std;

int sum(int, int);  //this is a prototype, it is mandatory if you type the function after main

// int sum(int a, int b);  --> Acceptable
// int sum(int a, b); --> not Acceptable
// void func(void); --> for void function

int main(){
    int num1 = 20, num2 = 53;
    cout<<sum(num1, num2)<<endl;
    // num1 and num2 are actual parameters
    return 0;
}

// a and b are formal parameters
int sum(int a, int b){
    int c = a + b;
    return c;
}