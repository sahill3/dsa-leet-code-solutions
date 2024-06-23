#include<iostream>
using namespace std;

int update1(int ** ptr){

    ptr = ptr + 2;

}

int update2(int ** ptr){

    *ptr = *ptr + 1;

}

int update3(int ** ptr){

    **ptr = **ptr + 1;
    cout << "Test: " << **ptr << endl;

}

int main(){
    
    int i = 4;
    int * p1 = &i;
    int ** p2 = &p1;

    cout << "i    = " << i << endl;
    cout << "&i   = " << &i << endl;
    cout << "p1   = " << p1 << endl;
    cout << "*p1  = " << *p1 << endl;
    cout << "*p2  = " << *p2 << endl;
    cout << "**p2 = " << **p2 << endl;
    cout << endl;

    cout << "<--- Function --->" << endl;

    cout << "Before: " << endl << "i: " << i << endl;
    cout << "p1: " << p1 << endl; 
    cout << "p2: " << p2 << endl;

    cout << endl << "After: " << endl; 
    update1(p2);
    cout << "Update1: " << endl;
    cout << "i: " << i << endl;
    cout << "p1: " << p1 << endl; 
    cout << "p2: " << p2 << endl;
    cout << endl;

    update3(p2);
    cout << "Update3: " << endl;
    cout << "i: " << i << endl;
    cout << "p1: " << p1 << endl; 
    cout << "p2: " << p2 << endl;
    cout << endl;

    update2(p2);
    cout << "Update2: " << endl;
    cout << "i: " << i << endl;
    cout << "p1: " << p1 << endl; 
    cout << "p2: " << p2 << endl;
    cout << endl;


    return 0;
}