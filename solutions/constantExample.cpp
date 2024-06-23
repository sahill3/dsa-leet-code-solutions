#include<iostream>
using namespace std;

int main()
{
    int a = 100;
    a = 50;         //now a = 50, 100 is overwritten
    cout<<a;
    const int b = 45;

    //b = 50;    this cannot be done, compiler will give an error
    return 0;
}
