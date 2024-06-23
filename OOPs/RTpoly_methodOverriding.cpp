#include<iostream>
using namespace std;

class Human{
    public:
    void speak(){
        cout << "Speaking" << endl;
    }
};

class Dog : public Human{
    public:
    void speak(){
        cout << "Barking" << endl;
    }
};

int main(){

    Human obj1;
    Dog obj2;

    obj1.speak();
    obj2.speak();

    return 0;
}