#include<iostream>
using namespace std;

void print(int a){
    if(a == 0)
        return;

    print(a-1);

    cout << a << endl;
} 

int main(){
    

    int i = 0;
    cin >> i;

    print(i);

    return 0;
}