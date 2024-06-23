#include<iostream>
using namespace std;

// int fibo(int a){
//     if(a == 2){
//         return 1;
//     }
//     else if(a == 1){
//         return 0;
//     }
//     return fibo(a-2) + fibo(a-1);  //reccursive function
// }

int fib(int a){
     if(a == 2){
        return 1;
    }
    else if(a == 1){
        return 0;
    }
    else{
        int n1 = 0, n2 = 1, n3;
        int temp = 0;
        while(temp != a){
            n3 = n1 + n2;
            n1= n2;
            n2 =n3;
            temp++;
        }
        return n3;
    }
}

int main(){
    int a;
    cout<<"Enter a number:";
    cin>>a;
    cout<<"The Nth term is :"<<fib(a);
    return 0;
}