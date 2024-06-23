#include<iostream>
using namespace std;

class B{
    public:
    int a;
    int b;

    void operator+ (B obj){
        int val1 = this->a;
        int val2 = obj.a;

        cout << "Output:" << val2-val1;
    }
};

int main(){
    
    B obj2, obj;

    obj.a = 4;
    obj2.a = 7;

    obj + obj2;

    return 0;
}