#include<iostream>
using namespace std;

//This will not change the value because the original variables are unaffected by this.
//onyl the copy is affected 
/*int swap(int a, int b){
    int temp = a;
    a = b;
    b =temp;
}*/
int swapPointer(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
} 

int swapByReference(int &a, int &b){  // Call by reference
    int temp = a;
    a = b;
    b = temp;   
}

int main(){
    int x = 8;
    int y = 32;
    cout<<"Value of x is "<<x<<" and value of y is "<<y<<endl;
    swapPointer(&x, &y);
    cout<<"Value of x is "<<x<<" and value of y is "<<y<<endl;
    swapByReference(x, y);
    cout<<"Value of x is "<<x<<" and value of y is "<<y<<endl;
    return 0;
}