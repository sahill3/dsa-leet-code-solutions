#include<iostream>
using namespace std;

void bubbleSort(int *arr, int size){
    if(size == 0 || size == 1)
        return;

    for(int i = 0; i < size-1; i++){
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }

    bubbleSort(arr, size-1);
}

int main(){

    int *arr = new int[10];

    arr[0] = 80;
    arr[1] = 50;
    arr[2] = 90;
    arr[3] = 20;
    arr[4] = 100;
    arr[5] = 10;
    arr[6] = 40;
    arr[7] = 60;
    arr[8] = 70;
    arr[9] = 30;

    bubbleSort(arr, 10);

    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    delete arr;
    
    return 0;
}