#include<iostream>
using namespace std;

void print(int *arr, int size, int start = 0){
    for(int i = start; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    
    int* arr = new int[5];

    arr[0] = 10; 
    arr[1] = 20; 
    arr[2] = 30; 
    arr[3] = 40; 
    arr[4] = 50; 

    print(arr, 5);

    cout << endl;
    
    print(arr, 5, 2);

    return 0;
}