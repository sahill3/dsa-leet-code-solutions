#include<iostream>
using namespace std;

class A{

    public:
    void print(){
        cout << "This is class A" << endl;
    }
};

class B{

    public:
    void print(){
        cout << "This is class B" << endl;
    }
};

class C : public A, public B{

};

int main(){
    C obj;
    obj.A::print();  //use scope resolution when 2 classes have same function name
    return 0;
}