#include<iostream>
using namespace std;

void selectionSort(int *arr, int size){
    if(size == 0 || size == 1)
        return;

    int minIndex = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < arr[minIndex])
            minIndex = i;
    }
    int temp = arr[0];
    arr[0] = arr[minIndex];
    arr[minIndex] = temp;

    selectionSort(arr+1, size-1);
}

int main(){

    int arr[5] = {400, 120, 50, 130, 100};

    selectionSort(arr, 5);

    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}