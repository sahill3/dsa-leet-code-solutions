#include<iostream>
using namespace std;
int main(){
    int counter = 0;
    int marks[4] = {89, 88, 70, 94};
    for(int i = 0; i < 4; i++){
        cout<<marks[i]<<endl;
    }
    cout<<"This is DO-WHILE LOOP"<<endl;
    do{
        cout<<marks[counter]<<endl;
        counter++;
    }while(counter < 4);

    cout<<"THIS IS EXTRACTING VALUES USING THE ARRAY POINTER"<<endl;
    int* p = marks;
    cout<<"The value at marks[0] is: "<<*p<<endl;
    cout<<"The value at marks[1] is: "<<*(p+1)<<endl;
    cout<<"The value at marks[2] is: "<<*(p+2)<<endl;
    cout<<"The value at marks[3] is: "<<*(p+3)<<endl;
    return 0;
}