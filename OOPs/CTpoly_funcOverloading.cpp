#include<iostream>
using namespace std;

// Compile time polymorphism - Function Overloading

class A{
    public:
    void sayHello(){
        cout << "Hi";
    }

    void sayHello(string name){
        cout << "Hello " << name;
    }
};

int main(){
    A obj;

    obj.sayHello();

    return 0;
}