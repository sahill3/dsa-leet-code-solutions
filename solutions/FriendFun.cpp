#include<iostream>
using namespace std;

class Complex{
    int a;
    int b;
    public:
        void set(int n1, int n2){
            a = n1;
            b = n2;
        }

        void print(void){
            cout<<"Your number is: "<<a<<" + "<<b<<"i"<<endl;
        }

        friend Complex add(Complex q1, Complex q2);
};

Complex add(Complex obj1, Complex obj2){
    Complex obj3;
    obj3.set((obj1.a+ obj2.a), (obj1.b + obj2.b));   
    
    return obj3;
}

int main(){
    Complex c1, c2, c3;
    c1.set(1, 4);
    c1.print();

    c2.set(5, 8);
    c2.print();

    c3 = add(c1, c2);
    c3.print();
    return 0;
}

//friend function does not need obj to be called, and it cannot be called by the obj 
//of the class whose members are being used
//cannot be invoked using an object
//can be declared inside private or public part of the class 
//It cannot access members directly by their name and need objects to access any member 