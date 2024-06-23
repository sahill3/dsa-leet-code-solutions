#include<iostream>
using namespace std;
int main(){
    
    int num = 5;
    int *p1 = &num;

    double d = 10.34;
    double *p2 = &d;

    cout << "Address of num is: " << p1 << endl;
    cout << "Value at p1 is: " << *p1 << endl; 
    cout << endl;

    cout << "Address of d is: " << p2 << endl;
    cout << "Value at p2 is: " << *p2 << endl;
    cout << endl;

    cout << "Size of int pointer is: " << sizeof(p1) << endl;    
    cout << "Size of double pointer is: " << sizeof(p2) << endl;
    cout << endl;

    int i = 10;
    int *p3 = 0;
    p3 = &i;
    cout << "Address of i is: " << p3 << endl;
    cout << "Value at p3 is: " << *p3 << endl;
    cout << endl;

    int j = i;
    i++;
    cout << "Value of j: " << j << endl;

    int *p4 = &j;

    (*p4)++;
    cout << "Value of j after (*p4)++: " << *p4 << endl;
    cout << endl;

    //Copying a pointer
    int *p5 = p4;
    cout << p4 << " - " << p5 << endl;
    cout << *p4 << " - " << *p5 << endl;
    cout << endl;

    int q = 5;
    int *p6 = &q;

    *p6 = *p6 + 1;
    cout << "Value after *p6 = *p6 + 1: " << *p6 << endl;
    cout << "Address before p6 = p6 + 1: " << p6 << endl;
    p6 = p6 + 1;
    cout << "Address after p6 = p6 + 1: " << p6 << endl;
    cout << "Value after p6 = p6 + 1: " << *p6 << endl;


    return 0;
}