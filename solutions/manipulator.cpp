#include<iostream>
#include<iomanip> 
using namespace std;
//manipulators are functions or keywords used to control the output
//setw aligns the output to the right as per the entered digit
//endl is a manipulator as-well

int main(){

    int a = 10, b = 144, c = 1557;
    cout<<"Value of a is:"<<setw(4)<<a<<endl;
    cout<<"Value of b is:"<<setw(4)<<b<<endl;
    cout<<"Value of c is:"<<setw(4)<<c<<endl;
}