#include<iostream>
using namespace std;

int sum(int a, int b){
    cout<<"Using function with 2 arguements."<<endl;
    return a + b;
}

int sum(int a, int b, int c){
    cout<<"Using function with 3 arguements."<<endl;
    return a + b + c;
}

int main(){
    cout<<sum(3,6)<<endl;
    cout<<sum(8, 7, 4)<<endl;
    return 0;
}