#include<iostream>
using namespace std;
int main(){
    const int a = 10;
    static int c = 120;
    c++;
    cout<<c;
    return 0;
}