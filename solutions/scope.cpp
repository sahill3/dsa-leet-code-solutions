#include<iostream>
using namespace std;

int a = 90;

int main(){
    int a = 10;
    cout<<"The Value of local a is: "<<a<<endl;
    cout<<"The value of Global a is: "<<::a;
    return 0;
}